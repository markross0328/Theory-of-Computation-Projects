#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

std::string print_sigmastar(const std::vector<char> alphabet_set, int length, int &num_strings);
int main()
{
    std::vector<char> alphabet_set;
    std::string input;
    int max_length, num_strings = 0;

    std::cout << "Enter an alphabet set -> ";
    std::cin >> input;

    std::cout << "Enter maximum length -> ";
    std::cin >> max_length;

    std::cout << std::endl;
    while (input.length() > 0)
    {
        alphabet_set.push_back(input[0]);
        input.erase(0, 1); // Remove the first character from the input string
    }

    if (max_length + alphabet_set.size() > 10)
    {
        std::cout << "The max length and alphabet set size is > 10";
    }
    else
    {
        std::cout << "Total number of strings = \n\n";

        for (int i = 0; i <= max_length; i++)
        {
            print_sigmastar(alphabet_set, i, num_strings);
            std::cout << std::endl;
        }
    }

    return 0;
}

std::string print_sigmastar(const std::vector<char> alphabet_set, int length, int &num_strings)
{
    std::cout << "Length = " << length << " | " << "Number of strings = " << pow(alphabet_set.size(), length) << std::endl;

    switch (length)
    {
    case 0:
        std::cout << "e -> " + std::to_string(num_strings) << std::endl;
        break;
    case 1:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            num_strings++;
            std::cout << alphabet_set[i] << " -> " + std::to_string(num_strings) << std::endl;
        }
        break;
    case 2:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                num_strings++;
                std::cout << alphabet_set[i] << alphabet_set[j] << " -> " + std::to_string(num_strings) << std::endl;
            }
        }
        break;
    case 3:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    num_strings++;
                    std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << " -> " + std::to_string(num_strings) << std::endl;
                }
            }
        }
        break;
    case 4:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    for (int l = 0; l < alphabet_set.size(); l++)
                    {
                        num_strings++;
                        std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << alphabet_set[l] << " -> " + std::to_string(num_strings) << std::endl;
                    }
                }
            }
        }
        break;
    case 5:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    for (int l = 0; l < alphabet_set.size(); l++)
                    {
                        for (int m = 0; m < alphabet_set.size(); m++)
                        {
                            num_strings++;
                            std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << alphabet_set[l] << alphabet_set[m] << " -> " + std::to_string(num_strings) << std::endl;
                        }
                    }
                }
            }
        }
        break;
    case 7:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    for (int l = 0; l < alphabet_set.size(); l++)
                    {
                        for (int m = 0; m < alphabet_set.size(); m++)
                        {
                            for (int n = 0; n < alphabet_set.size(); n++)
                            {
                                for (int o = 0; o < alphabet_set.size(); o++)
                                {
                                    num_strings++;
                                    std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << alphabet_set[l] << alphabet_set[m] << alphabet_set[n] << alphabet_set[o] << " -> " + std::to_string(num_strings) << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 8: 
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    for (int l = 0; l < alphabet_set.size(); l++)
                    {
                        for (int m = 0; m < alphabet_set.size(); m++)
                        {
                            for (int n = 0; n < alphabet_set.size(); n++)
                            {
                                for (int o = 0; o < alphabet_set.size(); o++)
                                {
                                    for (int p = 0; p < alphabet_set.size(); p++)
                                    {
                                        num_strings++;
                                        std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << alphabet_set[l] << alphabet_set[m] << alphabet_set[n] << alphabet_set[o] << alphabet_set[p] << " -> " + std::to_string(num_strings) << std::endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 9: 
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    for (int l = 0; l < alphabet_set.size(); l++)
                    {
                        for (int m = 0; m < alphabet_set.size(); m++)
                        {
                            for (int n = 0; n < alphabet_set.size(); n++)
                            {
                                for (int o = 0; o < alphabet_set.size(); o++)
                                {
                                    for (int p = 0; p < alphabet_set.size(); p++)
                                    {
                                        for (int q = 0; q < alphabet_set.size(); q++)
                                        {
                                            num_strings++;
                                            std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << alphabet_set[l] << alphabet_set[m] << alphabet_set[n] << alphabet_set[o] << alphabet_set[p] << alphabet_set[q] << " -> " + std::to_string(num_strings) << std::endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 10:
        for (int i = 0; i < alphabet_set.size(); i++)
        {
            for (int j = 0; j < alphabet_set.size(); j++)
            {
                for (int k = 0; k < alphabet_set.size(); k++)
                {
                    for (int l = 0; l < alphabet_set.size(); l++)
                    {
                        for (int m = 0; m < alphabet_set.size(); m++)
                        {
                            for (int n = 0; n < alphabet_set.size(); n++)
                            {
                                for (int o = 0; o < alphabet_set.size(); o++)
                                {
                                    for (int p = 0; p < alphabet_set.size(); p++)
                                    {
                                        for (int q = 0; q < alphabet_set.size(); q++)
                                        {
                                            for (int r = 0; r < alphabet_set.size(); r++)
                                            {
                                                num_strings++;
                                                std::cout << alphabet_set[i] << alphabet_set[j] << alphabet_set[k] << alphabet_set[l] << alphabet_set[m] << alphabet_set[n] << alphabet_set[o] << alphabet_set[p] << alphabet_set[q] << alphabet_set[r] << " -> " + std::to_string(num_strings) << std::endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    // Add cases for lengths greater than 10 if needed
    default:
        break;
    }
    return "";
}