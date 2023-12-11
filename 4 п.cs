using System;

namespace Project
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Enter a decimal fraction: ");
            string input = Console.ReadLine();
            if (double.TryParse(input, out double decimalFraction))
            {
                Console.WriteLine("Enter the base of the number system (2 - 36): ");
                int baseNumber = Convert.ToInt32(Console.ReadLine());
                string result = ConvertDecimalFractionToBase(decimalFraction, baseNumber);
                Console.WriteLine($"Fraction in base {baseNumber}: {result}");
            }
            else
            {
                Console.WriteLine("The entered value is not a decimal fraction");
            }
        }

        public static string ConvertDecimalFractionToBase(double decimalFraction, int baseNumber)
        {
            string result = "";
            string integerPartResult = "";
            string fractionPartResult = "";

            int integerPart = (int)decimalFraction;
            double fractionPart = (decimalFraction - integerPart) * baseNumber;

            while (integerPart >= baseNumber)
            {
                if ((integerPart % baseNumber) >= 10 && (integerPart) % baseNumber <= 36)
                {
                    integerPartResult += (char)((integerPart % baseNumber) - 10 + 'A');
                }
                else
                {
                    integerPartResult += integerPart % baseNumber;
                }
                integerPart /= baseNumber;

            }

            if (integerPart >= 10 && integerPart <= 36)
            {
                integerPartResult += (char)(integerPart - 10 + 'A');
            }
            else
            {
                integerPartResult += integerPart;
            }

            while (fractionPart >= 0.001 && fractionPartResult.Length < 20)
            {
                if ((int)fractionPart >= 10 && (int)fractionPart <= 36)
                {
                    fractionPartResult += (char)((int)fractionPart - 10 + 'A');
                }
                else
                {
                    fractionPartResult += (int)fractionPart;
                }
                fractionPart = (fractionPart - (int)fractionPart) * baseNumber;
            }

            integerPartResult = ReverseString(integerPartResult);
            result = integerPartResult + "," + fractionPartResult;

            return result;
        }

        public static string ReverseString(string s)
        {
            char[] arr = s.ToCharArray();
            Array.Reverse(arr);
            return new string(arr);
        }
    }
}