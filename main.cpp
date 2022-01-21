#include "benchmark.hpp"

#include <cmath>
#include <iostream>

#include "cpp17/cpp17Demos.hpp"
#include "cpp20/cpp20Demos.hpp"

#define RUN_CONCEPT_DEMOS 0
#define RUN_RANGES_DEMOS 0
#define RUN_COROUTINES_DEMOS 0
#define RUN_TREE_WAY_COMP_DEMOS 0
#define RUN_DESIGNATED_INIT_DEMOS 0
#define RUN_RANGE_BASED_LOOP_INIT_DEMOS 0
#define RUN_CONSTEXPR_VIRTUAL_FUNC_DEMOS 0
#define RUN_CONSTINIT_DEMOS 0
#define RUN_LIKELY_UNLIKELY_DEMOS 0
#define RUN_NO_UNIQUE_ADDR_DEMOS 0
#define RUN_TEMPLATE_LAMBDA_DEMOS 0
#define RUN_LAMBDA_CAPTURES_DEMOS 0
#define RUN_NON_TYPE_TEMPLATE_PARAM_DEMOS 0
#define RUN_VOLATILE_DEMOS 0

int main(int, char **)
{
#if RUN_CONCEPT_DEMOS
    // Constraints and concepts
    std::cout << "********** Constraints and concepts **********\n";
    cpp17::integralCheckDemo();
    cpp20::predefinedIntegralConceptDemo();
    cpp17::hasMemberFuncDemo();
    cpp20::hasMemberFuncConstraintsDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_RANGES_DEMOS
    // Ranges Library
    std::cout << "*************** Ranges Library ***************\n";
    cpp17::evenSquareDemo();
    cpp20::evenSquareDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_COROUTINES_DEMOS
    // Coroutines
    std::cout << "**************** Coroutines ******************\n";
    cpp20::generatorDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_TREE_WAY_COMP_DEMOS
    // Three way comparison
    std::cout << "************ Three way comparison ************\n";
    cpp17::threeCompDemo();
    cpp20::threeWayCompDemo();
    cpp17::threeCompOperatorOverloadDemo();
    cpp20::threeWayOperatorOverloadDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_DESIGNATED_INIT_DEMOS
    // Designated initializer
    std::cout << "*********** Designated initializer ***********\n";
    cpp17::designatedInitializerDemo();
    cpp20::designatedInitializerDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_RANGE_BASED_LOOP_INIT_DEMOS
    // init-statement in range based loop
    std::cout << "* init-statement in range based loop *\n";
    cpp17::addLineNumber();
    cpp20::addLineNumber();
    cpp17::danglingReference();
    cpp20::ubFree();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_CONSTEXPR_VIRTUAL_FUNC_DEMOS
    // constexpr virtual function
    std::cout << "********** constexpr virtual function ********\n";
    cpp17::constVirtualFunctionDemo();
    cpp20::constexprVirtualFunctionDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_CONSTINIT_DEMOS
    // constinit
    std::cout << "****************** constinit *****************\n";
    cpp17::withoutConstinitDemo();
    cpp20::constinitDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_LIKELY_UNLIKELY_DEMOS
    // likely unlikely
    std::cout << "************** likely unlikely ***************\n";
    benchmark(cpp17::cos, "Without attributes");
    benchmark(cpp20::cos, "With attributes");
    benchmark<double(double)>(std::cos, "std::cos");
    std::cout << "**********************************************\n\n";
#endif

#if RUN_NO_UNIQUE_ADDR_DEMOS
    // no_unique_address
    std::cout << "************* no_unique_address **************\n";
    cpp17::emptyClassDemo();
    cpp20::emptyClassDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_TEMPLATE_LAMBDA_DEMOS
    // template lambda
    std::cout << "**************** template lambda *************\n";
    cpp17::genericLambdaDemo();
    cpp20::templateLambdaDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_LAMBDA_CAPTURES_DEMOS
    // lambda captures
    std::cout << "**************** capture list demo *************\n";
    cpp17::captureListDemo();
    cpp20::captureListDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_NON_TYPE_TEMPLATE_PARAM_DEMOS
    // Non-type template parameter
    std::cout << "********* Non-type template parameter ********\n";
    cpp17::stringLiteralAsTemplateParameterDemo();
    cpp20::stringLiteralAsTemplateParameterDemo();
    std::cout << "**********************************************\n\n";
#endif

#if RUN_VOLATILE_DEMOS
    // volatile usage
    std::cout << "*************** volatile usage ***************\n";
    cpp17::incrementDecrementOperand();
    cpp20::incrementDecrementOperand();
    cpp17::directCompundAssignment();
    cpp20::directCompundAssignment();
    cpp17::functionParameter();
    cpp20::functionParameter();
    cpp17::functionReturnValue();
    cpp20::functionReturnValue();
    cpp17::structBinding();
    cpp20::structBinding();
    std::cout << "**********************************************\n\n";
#endif
}
