#include <iostream>
#include <string>
class binary_input
{
    int binary{0};

public:
    void read()
    {
        std::cout << "Enter the binary number :- ";
        std::cin >> binary;
    }
    friend void conversion_binary_to_decimal();
    friend void conversion_binary_to_hexadecimal();
};
class decimal_input
{
    int decimal{0};

public:
    void read()
    {
        std::cout << "Enter the decimal number :- ";
        std::cin >> decimal;
    }
    friend void conversion_decimal_to_hexadecimal();
    friend void conversion_decimal_to_binary();
};
class hexadecimal_input
{
    std::string hexadecimal_decimal;

public:
    void read()
    {
        std::cout << "Enter the hexadecimal number :- ";
        getline(std::cin >> std::ws, hexadecimal_decimal);
    }
    friend void conversion_hexadecimal_to_binary();
    friend void conversion_hexadecimal_to_decimal();
};
class string_input
{
    std::string words;

public:
    void read()
    {
        std::cout << "Enter the string :- ";
        getline(std::cin >> std::ws, words); // cin>>ws clear white spaces which avoid garbage {\n} to let in and skip into the function
    }
    friend void conversion_string_to_decimal();
    friend void conversion_string_to_binary();
    friend void conversion_string_to_hexadecimal();
};
class single_gate_input
{
    int gate_input{0};

public:
    void read()
    {
        std::cout << "Enter the gate input of A :- ";
        std::cin >> gate_input;
        std::cout << std::endl
             << "Output of operation is => ";
    }
    friend void NOT();
};
class double_gate_input
{
    int gate_1_input{0}, gate_2_input{0};

public:
    void read()
    {
        std::cout << "Enter the gate input of A :- ";
        std::cin >> gate_1_input;
        std::cout << "Enter the gate input of B :- ";
        std::cin >> gate_2_input;
        std::cout << std::endl
             << "Output of operation is => ";
    }
    friend void OR();
    friend void AND();
    friend void NAND();
    friend void NOR();
    friend void XOR();
};
class base_convertion : public binary_input, public hexadecimal_input, public decimal_input, public string_input
{
public:
    int binary_to_decimal(int binary)
    {
        int binary_constant{1}, number{0};
        while (1)
        {
            if (binary > 0)
            {
                number = number + binary_constant * (binary % 10);
                binary = binary / 10;
                binary_constant = binary_constant * 2;
            }
            else
            {
                return number;
            }
        }
    }
    int decimal_to_binary(int decimal)
    {
        int temp{1}, number{0};
        while (1)
        {
            if (decimal > 0)
            {
                number = number + temp * (decimal % 2);
                decimal = decimal / 2;
                temp = temp * 10;
            }
            else
            {
                return number;
            }
        }
    }
    void string_to_binary(std::string words)
    {
        int i = 0;
        while (words[i] != '\0')
        {
            int binary_code = decimal_to_binary(words[i]);
            std::cout << binary_code << " ";
            i++;
        }
    }
    void binary_to_string()
    {
        int i = 0, numbers{0};
        std::cout << "Enter the number of binary number :- ";
        std::cin >> numbers;
        int binary_array[numbers];
        std::cout << std::endl;
        std::cout << "Enter the binary numbers :- ";
        for (i = 0; i < numbers; i++)
        {
            std::cin >> binary_array[i];
        }
        for (i = 0; i < numbers; i++)
        {
            int ascii = binary_to_decimal(binary_array[i]);
            char word = ascii;
            std::cout << word;
        }
    }
    void string_to_decimal(std::string words)
    {
        int i = 0;
        while (words[i] != '\0')
        {
            int decimal_code = words[i];
            std::cout << decimal_code << " ";
            i++;
        }
    }
    void decimal_to_string()
    {
        int i = 0, numbers{0};
        std::cout << "Enter the number of decimal number :- ";
        std::cin >> numbers;
        int decimal_array[numbers];
        std::cout << std::endl;
        std::cout << "Enter the decimal numbers :- ";
        for (i = 0; i < numbers; i++)
        {
            std::cin >> decimal_array[i];
        }
        for (i = 0; i < numbers; i++)
        {
            char word = decimal_array[i];
            std::cout << word;
        }
    }
    void decimal_to_hexadecimal(int decimal)
    {
        int number = decimal * 16;
        float float_of_number = decimal;
        while (float_of_number > 16)
        {
            float_of_number = float_of_number / 16;
        }
        do
        {
            decimal = float_of_number;
            if (decimal % 16 < 10)
            {
                std::cout << decimal % 16;
                float_of_number = float_of_number * 16;
            }
            else
            {
                char z = decimal % 16 + 55;
                std::cout << z;
                float_of_number = float_of_number * 16;
            }
        } while (float_of_number != number);
    }
    void binary_to_hexadecimal(int binary)
    {
        decimal_to_hexadecimal(binary_to_decimal(binary));
    }
    void string_to_hexadecimal(std::string words)
    {
        int i{0};
        while (words[i] != '\0')
        {
            int decimal = words[i];
            decimal_to_hexadecimal(decimal);
            std::cout << " ";
            i++;
        }
    }
    int hexadecimal_to_decimal(std::string hexadecimal)
    {
        int number{0}, size = hexadecimal.size(), i{0};
        while (hexadecimal[i] != '\0')
        {
            if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
            {
                int decimal = hexadecimal[i] - 48;
                for (int k = 0; k < size - i; k++)
                {
                    decimal = decimal * 16;
                }
                number = number + decimal;
            }
            else
            {
                int decimal = hexadecimal[i] - 55;
                for (int k = 0; k < size - i; k++)
                {
                    decimal = decimal * 16;
                }
                number = number + decimal;
            }
            i++;
        }
        number = number / 16;
        return number;
    }
    int hexadecimal_to_binary(std::string hexadecimal)
    {
        return decimal_to_binary(hexadecimal_to_decimal(hexadecimal));
    }
    void hexadecimal_to_string()
    {
        int number_of_hexadecimal{0};
        std::cout << "Enter number of hexadecimal :- ";
        std::cin >> number_of_hexadecimal;
        std::string array_of_hexadecimal[number_of_hexadecimal];
        std::cout << std::endl;
        std::cout << "Enter the hexadecimal numbers :- ";
        for (int i = 0; i < number_of_hexadecimal; i++)
        {
            std::cin >> array_of_hexadecimal[i];
        }
        for (int i = 0; i < number_of_hexadecimal; i++)
        {
            char word = hexadecimal_to_decimal(array_of_hexadecimal[i]);
            std::cout << word;
        }
    }
    friend void conversion_binary_to_decimal();
    friend void conversion_binary_to_hexadecimal();
    friend void conversion_decimal_to_hexadecimal();
    friend void conversion_decimal_to_binary();
    friend void conversion_hexadecimal_to_binary();
    friend void conversion_hexadecimal_to_decimal();
    friend void conversion_string_to_decimal();
    friend void conversion_string_to_binary();
    friend void conversion_string_to_hexadecimal();
};
class gate_operation : public single_gate_input, public double_gate_input
{
public:
    int NOT(int A)
    {
        if (A == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int OR(int A, int B)
    {
        if (A + B == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int AND(int A, int B)
    {
        if (A * B == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int NAND(int A, int B)
    {
        return NOT(AND(A, B));
    }
    int NOR(int A, int B)
    {
        return NOT(OR(A, B));
    }
    int XOR(int A, int B)
    {
        return A * NOT(B) + B * NOT(A);
    }
    friend void NOT();
    friend void OR();
    friend void AND();
    friend void NAND();
    friend void NOR();
    friend void XOR();
};

void conversion_binary_to_decimal()
{
    base_convertion c;
    c.binary_input::read();
    std::cout << c.binary_to_decimal(c.binary) << std::endl;
}
void conversion_binary_to_hexadecimal()
{
    base_convertion c;
    c.binary_input::read();
    c.binary_to_hexadecimal(c.binary);
}
void conversion_decimal_to_hexadecimal()
{
    base_convertion c;
    c.decimal_input::read();
    c.decimal_to_hexadecimal(c.decimal);
}
void conversion_decimal_to_binary()
{
    base_convertion c;
    c.decimal_input::read();
    std::cout << c.decimal_to_binary(c.decimal) << std::endl;
}
void conversion_hexadecimal_to_binary()
{
    base_convertion c;
    c.hexadecimal_input::read();
    std::cout << c.hexadecimal_to_binary(c.hexadecimal_decimal);
}
void conversion_hexadecimal_to_decimal()
{
    base_convertion c;
    c.hexadecimal_input::read();
    std::cout << c.hexadecimal_to_decimal(c.hexadecimal_decimal);
}
void conversion_string_to_decimal()
{
    base_convertion c;
    c.string_input::read();
    c.string_to_decimal(c.words);
}
void conversion_string_to_binary()
{
    base_convertion c;
    c.string_input::read();
    c.string_to_binary(c.words);
}
void conversion_string_to_hexadecimal()
{
    base_convertion c;
    c.string_input::read();
    c.string_to_hexadecimal(c.words);
}

void NOT()
{
    gate_operation g;
    g.single_gate_input::read();
    std::cout << g.NOT(g.gate_input) << std::endl;
}
void OR()
{
    gate_operation g;
    g.double_gate_input::read();
    std::cout << g.OR(g.gate_1_input, g.gate_2_input) << std::endl;
}
void AND()
{
    gate_operation g;
    g.double_gate_input::read();
    std::cout << g.AND(g.gate_1_input, g.gate_2_input) << std::endl;
}
void NAND()
{
    gate_operation g;
    g.double_gate_input::read();
    std::cout << g.NAND(g.gate_1_input, g.gate_2_input) << std::endl;
}
void NOR()
{
    gate_operation g;
    g.double_gate_input::read();
    std::cout << g.NOR(g.gate_1_input, g.gate_2_input) << std::endl;
}
void XOR()
{
    gate_operation g;
    g.double_gate_input::read();
    std::cout << g.XOR(g.gate_1_input, g.gate_2_input) << std::endl;
}

int main()
{
    base_convertion c;
    gate_operation g;

    while (1)
    {
        std::cout << std::endl;
        std::cout << "Enter 0 to Exit" << std::endl;
        std::cout << "Enter 1 for base conversion" << std::endl;
        std::cout << "Enter 2 for conversion of base values with string" << std::endl;
        std::cout << "Enter 3 for output of logic gates" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice :- ";
        int choice;
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            std::cout << "1-> From decimal" << std::endl;
            std::cout << "2-> From binary" << std::endl;
            std::cout << "3-> From hexadecimal" << std::endl;
            std::cout << "Enter your choice :- ";
            int from_choice;
            std::cin >> from_choice;
            std::cout << std::endl;
            switch (from_choice)
            {
            case 1:
                std::cout << "1-> To binary" << std::endl;
                std::cout << "2-> To hexadecimal" << std::endl;
                std::cout << "Enter your choice :- ";
                int to_choice_1;
                std::cin >> to_choice_1;
                std::cout << std::endl;
                switch (to_choice_1)
                {
                case 1:
                    std::cout << "Conversion from decimal to binary" << std::endl;
                    conversion_decimal_to_binary();
                    std::cout << std::endl;
                    break;
                case 2:
                    std::cout << "Conversion from decimal to hexadecimal" << std::endl;
                    conversion_decimal_to_hexadecimal();
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            case 2:
                std::cout << "1-> To decimal" << std::endl;
                std::cout << "2-> To hexadecimal" << std::endl;
                std::cout << "Enter your choice :- ";
                int to_choice_2;
                std::cin >> to_choice_2;
                std::cout << std::endl;
                switch (to_choice_2)
                {
                case 1:
                    std::cout << "Conversion from binary to decimal" << std::endl;
                    conversion_binary_to_decimal();
                    std::cout << std::endl;
                    break;
                case 2:
                    std::cout << "Conversion from binary to hexadecimal" << std::endl;
                    conversion_binary_to_hexadecimal();
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            case 3:
                std::cout << "1-> To decimal" << std::endl;
                std::cout << "2-> To binary" << std::endl;
                std::cout << "Enter your choice :- ";
                int to_choice_3;
                std::cin >> to_choice_3;
                std::cout << std::endl;
                switch (to_choice_3)
                {
                case 1:
                    std::cout << "Conversion from hexadecimal to decimal" << std::endl;
                    conversion_hexadecimal_to_decimal();
                    std::cout << std::endl;
                    break;
                case 2:
                    std::cout << "Conversion from hexadecimal to binary" << std::endl;
                    conversion_hexadecimal_to_binary();
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            default:
                std::cout << std::endl;
                std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                std::cout << std::endl;
                break;
            }
            break;
        case 2:
            std::cout << "1-> From string" << std::endl;
            std::cout << "2-> To string" << std::endl;
            int string_choice;
            std::cout << "Enter your choice :- ";
            std::cin >> string_choice;
            std::cout << std::endl;
            switch (string_choice)
            {
            case 1:
                std::cout << "1-> To decimal/ascii value" << std::endl;
                std::cout << "2-> To binary" << std::endl;
                std::cout << "3-> To hexadecimal" << std::endl;
                std::cout << "Enter your choice :- ";
                int string_choice_1;
                std::cin >> string_choice_1;
                std::cout << std::endl;
                switch (string_choice_1)
                {
                case 1:
                    std::cout << "Conversion from string to decimal/ascii value" << std::endl;
                    conversion_string_to_decimal();
                    std::cout << std::endl;
                    break;
                case 2:
                    std::cout << "Conversion from string to binary" << std::endl;
                    conversion_string_to_binary();
                    std::cout << std::endl;
                    break;
                case 3:
                    std::cout << "Conversion from string to hexadecimal" << std::endl;
                    conversion_string_to_hexadecimal();
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            case 2:
                std::cout << "1-> From decimal/ascii value" << std::endl;
                std::cout << "2-> From binary" << std::endl;
                std::cout << "3-> From hexadecimal" << std::endl;
                std::cout << "Enter your choice :- ";
                int string_choice_2;
                std::cin >> string_choice_2;
                std::cout << std::endl;
                switch (string_choice_2)
                {
                case 1:
                    std::cout << "Conversion from decimal/ascii value to string" << std::endl;
                    c.decimal_to_string();
                    std::cout << std::endl;
                    break;
                case 2:
                    std::cout << "Conversion from binary to string" << std::endl;
                    c.binary_to_string();
                    std::cout << std::endl;
                    break;
                case 3:
                    std::cout << "Conversion from hexadecimal to string" << std::endl;
                    c.hexadecimal_to_string();
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            default:
                std::cout << std::endl;
                std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                std::cout << std::endl;
                break;
            }
            break;
        case 3:
            std::cout << "1-> basic gates " << std::endl;
            std::cout << "2-> universal gates " << std::endl;
            int gates_choice;
            std::cout << "Enter your choice :- ";
            std::cin >> gates_choice;
            std::cout << std::endl;
            switch (gates_choice)
            {
            case 1:
                std::cout << "1-> NOT" << std::endl;
                std::cout << "2-> AND" << std::endl;
                std::cout << "3-> OR" << std::endl;
                int basic_gates_choice;
                std::cout << "Enter your choice :- ";
                std::cin >> basic_gates_choice;
                std::cout << std::endl;
                switch (basic_gates_choice)
                {
                case 1:
                    std::cout << "NOT gate is executed" << std::endl
                         << std::endl;
                    NOT();
                    break;
                case 2:
                    std::cout << "AND gate is executed" << std::endl
                         << std::endl;
                    AND();
                    break;
                case 3:
                    std::cout << "OR gate is executed" << std::endl
                         << std::endl;
                    OR();
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            case 2:
                std::cout << "1-> NAND" << std::endl;
                std::cout << "2-> NOR" << std::endl;
                std::cout << "3-> XOR" << std::endl;
                int universal_gates_choice;
                std::cout << "Enter your choice :- ";
                std::cin >> universal_gates_choice;
                std::cout << std::endl;
                switch (universal_gates_choice)
                {
                case 1:
                    std::cout << "NAND gate is executed" << std::endl
                         << std::endl;
                    NAND();
                    break;

                case 2:
                    std::cout << "NOR gate is executed" << std::endl
                         << std::endl;
                    NOR();
                    break;
                case 3:
                    std::cout << "XOR gate is executed" << std::endl
                         << std::endl;
                    XOR();
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            default:
                std::cout << std::endl;
                std::cout << "OPPS! You have Entered wrong choice" << std::endl;
                std::cout << std::endl;
                break;
            }
            break;
        default:
            std::cout << std::endl;
            std::cout << "OPPS! You have Entered wrong choice" << std::endl;
            std::cout << std::endl;
            break;
        }
    }
}