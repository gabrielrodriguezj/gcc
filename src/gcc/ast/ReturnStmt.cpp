#include "gcc/ast/ReturnStmt.hpp"

ReturnStmt :: ReturnStmt(std::unique_ptr<Expression>  expression) : expression(std::move(expression)) {

}