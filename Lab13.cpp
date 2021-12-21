// Lab13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "struct.h"

int main()// не работает с длинными названиями!!!!
{
    enum TASK { SORT_PASSPORT = 1, SELECTION, FIND_FEMALE , CHANGE_ELEMENT};
    const char* const task[] = { "SORT_PASSPORT", "SELECTION", "FIND_FEMALE", "CHANGE_ELEMENT", "end"};
    std::vector <Worker> workers;

    char answer;
    std::cout << "Do you want fill bin file of workers?(y/n) ";
    answer = getchar();
    if (answer == 'y')
    {
        int n = 0;
        std::cout << "Input n workers ";
        std::cin >> n;
        initconsol(workers, n);
        printconsol(workers);
        printbinfile(workers);
        workers.clear();
    }

    fillVectorFromBin(workers);
    printconsol(workers);

    std::cout << "Do you want correct bin file?(y/n) ";
    std::cin.ignore();
    answer = getchar();
    if (answer == 'y')
        changeElement(workers);

    for (int i = 0; task[i] != "end"; i++)
        std::cout << i + 1 << ")" << task[i] << "\n";

    int z;
    while (true)
    {
        std::cin >> z;
        switch (z)
        {
        case TASK::SORT_PASSPORT:  {
            sort
            (
                workers.begin(),
                workers.end(),
                [](Worker a, Worker b)
                {
                    int minSize = 0;
                    (a.password.size() <= b.password.size()) ? minSize = a.password.size() :
                        minSize = b.password.size();

                    for(int i = 0; i < minSize; i++)
                        if(a.password[i] != b.password[i])
                            return a.password[i] < b.password[i];
                    return a.password[0] < b.password[0];// на всякий случай
                }
            );
            printconsol(workers);
            break;
        }
        case TASK::SELECTION: {
            std::vector<Worker> sel = selection(workers);
            printconsol(sel);
            break;
        }
        case TASK::FIND_FEMALE: {
            Worker t = findFemale(workers);
            std::cout << t;
            break;
        }
        case TASK::CHANGE_ELEMENT: {
            printconsol(workers);
            changeElement(workers);
            break;
        }
        }
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
