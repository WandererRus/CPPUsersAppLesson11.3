// CPPUsersAppLesson11.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int number = 0;
    FILE* myfile;
    FILE* newfile;
    fopen_s(&myfile, "D:\\test.txt", "r");
    fopen_s(&newfile, "D:\\testcopy.txt", "w");
    while (!feof(myfile))
    {
        number = fgetc(myfile);
        if (number >= 0)
            fputc(number, newfile);
    }
    fclose(myfile);
    fclose(newfile);


    std::string text;
    fopen_s(&myfile, "D:\\test.txt", "r");

    while (!feof(myfile))
    {
        number = fgetc(myfile);
        if (number >= 0)
            text.push_back((char)number);
    }
    int length = text.length();
    int stringcount = 1;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '\n')
            stringcount++;
    }



    std::string* massiveString = new std::string[stringcount];
    int counter = 0;
    char buf[128];
    fclose(myfile);
    fopen_s(&myfile, "D:\\test.txt", "r");  
    fopen_s(&newfile, "D:\\testcopyreverse.txt", "w");
    while (!feof(myfile))
    {
        massiveString[counter] = fgets(buf, 127, myfile);
                
        counter++;
    }
    for (int i = stringcount-1; i >= 0; i--)
    {        
        for (int j = 0; j < massiveString[i].length(); j++)
        {
            fputc(massiveString[i][j], newfile);
            if (i == stringcount - 1 && j == massiveString[i].length() - 1)
            {
                fputc('\n', newfile);
            }
        }
        
    }
    
    fclose(myfile);
    fclose(newfile);

    fopen_s(&myfile, "D:\\task4.txt", "r");
    int stringcount2 = 5;
    std::string* massiveString2 = new std::string[stringcount2];
    int counter2 = 0;
    char buf2[128];
    bool existSpace = false;
    bool onceExistSpace = false;
    while (!feof(myfile))
    {
        massiveString[counter2] = fgets(buf2, 127, myfile);
        counter2++;
    }
    fopen_s(&newfile, "D:\\task4result.txt", "w");
    for (int i = 0; i < stringcount2; i++)
    {
        for(int j = 0; j < massiveString[i].length(); j++)
        {
            fputc(massiveString[i][j], newfile);            
            if (massiveString[i][j] == 32)
            {
                existSpace = true;
                onceExistSpace = true;
            }
        }
        if (existSpace)
        {
            existSpace = false;
            for (int j = 0; j < 12; j++)
            {
                fputc('-', newfile);
            }
            fputc('\n', newfile);
        }
    }
    if (!onceExistSpace)
    {
        fputc('\n', newfile);
        for (int j = 0; j < 12; j++)
        {
            fputc('-', newfile);
        }
    }

    fclose(myfile);
    fclose(newfile);

    
    return 0;
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
