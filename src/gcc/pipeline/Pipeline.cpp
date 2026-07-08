#include "../../../include/gcc/pipeline/Pipeline.hpp"

void Pipeline::addPass(std::unique_ptr<Pass> pass){
    passes_.push_back(std::move(pass));
}

int Pipeline::run(CompilerContext& context) const {
    for (auto& pass : passes_) {
        pass->run(context);
    }

    return 0;
}
