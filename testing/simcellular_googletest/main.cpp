#include "tst_cell.h"
#include "tst_color.h"
#include "tst_game.h"
#include "tst_library.h"
#include "tst_widget.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
