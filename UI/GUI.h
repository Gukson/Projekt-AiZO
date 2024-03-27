//
// Created by Kuba on 12/03/2024.
//

#ifndef AIZO_GUI_H
#define AIZO_GUI_H
#include "../generator/DataGenerator.h"
#include "../sorting_algorithms/heap_sort/heap_sort.h"
#include "../sorting_algorithms/quick_sort/QuickSort.h"
#include "../sorting_algorithms/shell_sort/ShellSort.h"
#include "../sorting_algorithms/insert_sort/insert_sort.h"


class GUI {
    public:
        void mainMenu();
};
#include "testHeapSort.h"
#include "testQuickSort.h"
#include "testShellSort.h"
#include "testEverything.h"
#include "GUI.tpp"
#endif //AIZO_GUI_H