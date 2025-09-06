#include <iostream>

#include "cpp11/feature_modules/module08_third_party/demonstrate_third_party.h"
#include "thirdparty/mypath2/mymath2.h"

void demonstrate_third_party_basic()
{
    /**
     * 1, make sure link libs directory
     target_link_directories(${PROJECT_NAME}
        PRIVATE
        $<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/libs/lib/Windows>
        $<$<PLATFORM_ID:Linux>:${CMAKE_CURRENT_SOURCE_DIR}/libs/lib/Linux>
    )

    * 2, make sure link the exact lib you need, here we need the mymath2.lib
    target_link_libraries(${PROJECT_NAME} 
        PRIVATE 
        mymath2
    )
     */
    std::cout << "1 + 2 = " << add2(1, 2) << std::endl;
}