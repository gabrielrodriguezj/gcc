#include "gcc/driver/CompilerDriver.hpp"

#include <iostream>

#include "../../../include/gcc/diagnostics/consumers/ConsoleDiagnosticConsumer.hpp"
#include "../../../include/gcc/diagnostics/formatters/PlainDiagnosticFormatter.hpp"
#include "gcc/driver/CommandLineParser.hpp"
#include "gcc/driver/CompilerContext.hpp"
#include "gcc/pipeline/LexerPass.hpp"
#include "gcc/pipeline/ParserPass.hpp"
#include "gcc/pipeline/Pipeline.hpp"

int CompilerDriver::run(int argc, char **argv) {

    int result = 0;

    try {
        // Parsing the arguments
        CommandLineParser parser;
        CompilerOptions options = parser.parse(argc, argv);

        // Creating the source manager
        auto sourceManager = std::make_unique<SourceManager>(options.inputFile);

        // Creating the diagnostics engine
        auto formatter = std::make_unique<PlainDiagnosticFormatter>(*sourceManager);
        auto consumer = std::make_unique<ConsoleDiagnosticConsumer>(*formatter);
        auto diagnosticEngine = std::make_unique<DiagnosticEngine>(*consumer);

        // Creating the Compiler Context
        CompilerContext context(
            options,
            (std::move(sourceManager)),
            (std::move(diagnosticEngine)));

        const Pipeline pipeline = buildPipeline((options));

        result = pipeline.run(context);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        result = -1;
    }

    return result;
}

Pipeline CompilerDriver::buildPipeline(const CompilerOptions& options)
{
    Pipeline pipeline;

    if (options.runLexer) {
        pipeline.addPass(std::make_unique<LexerPass>());
    }

    if (options.runParser) {
        pipeline.addPass(std::make_unique<ParserPass>());
    }

    return pipeline;
}

