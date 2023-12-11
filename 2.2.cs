using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex2
{

    internal class Program
    {

        static void Main(string[] args)
        {
            List<int> items = new List<int>() { 1, 2, 3, 4 };
            int numberOfItems = 2;
            EqulityComparerRealizate comparerRealizate = new EqulityComparerRealizate();

            try
            {
                Console.WriteLine("Combinations:");
                ToConsole(items.GetCombinations(numberOfItems, comparerRealizate), comparerRealizate);

                Console.WriteLine("Combinations With No Repetitions:");
                ToConsole(items.GetCombinationsNoRepetitions(numberOfItems, comparerRealizate), comparerRealizate);

                Console.WriteLine("Subsets:");
                ToConsole(items.GetSubsets(comparerRealizate), comparerRealizate);

                Console.WriteLine("Rearrangements:");
                ToConsole(items.GetRearrangements(comparerRealizate), comparerRealizate);
            }
            catch (ArgumentNullException ex) { Console.WriteLine(ex.Message); }
            catch (ArgumentException ex) { Console.WriteLine(ex.Message); }

        }

        static void ToConsole(IEnumerable<IEnumerable<int>> items, EqulityComparerRealizate comparerRealizate)
        {
            int n = 0;
            foreach (List<int> s in items)
            {
                n++;
                Console.Write("[ ");
                foreach (int i in s)
                {
                    Console.Write(i + " ");
                }
                Console.Write("]");
                Console.WriteLine();
            }
            
            Console.WriteLine();

        }
    }
}