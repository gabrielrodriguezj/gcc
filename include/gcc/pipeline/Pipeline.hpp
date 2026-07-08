#ifndef GCC_PIPELINE_HPP
#define GCC_PIPELINE_HPP
#include <memory>

#include "../driver/CompilerContext.hpp"
#include "Pass.hpp"

class Pipeline {
public:
    void addPass(std::unique_ptr<Pass> pass);
    int run(CompilerContext& context) const;

private:
    std::vector<std::unique_ptr<Pass>> passes_;
};

#endif //GCC_PIPELINE_HPP
