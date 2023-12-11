using Ex3;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using static Ex3.ArrayExtension;

namespace Ex3
{
    internal class Program
    {
        public delegate int comparisonDelegate<in T>(T x, T y);


        static void Main(string[] args)
        {

            List<string> stringsDefault = new List<string>() { "22", "1", "333", "4444", "666666", "55555", "88888888", "7777777" }; ;
            List<string> strings;

            try
            {
                strings = stringsDefault.ToList();
                strings.SortExtend(ref strings, ArrayExtension.Order.Ascending, ArrayExtension.Algorithm.Selection, new IComparer());
                Console.WriteLine(); Console.Write("Selection:\t");
                foreach (string s in strings) { Console.Write(s + " "); }

                strings = stringsDefault.ToList();
                strings.SortExtend(ref strings, ArrayExtension.Order.Ascending, ArrayExtension.Algorithm.Inserts, new IComparer());
                Console.WriteLine(); Console.Write("Inserts:\t");
                foreach (string s in strings) { Console.Write(s + " "); }

                strings = stringsDefault.ToList();
                strings.SortExtend(ref strings, ArrayExtension.Order.Ascending, ArrayExtension.Algorithm.Merge, new IComparer());
                Console.WriteLine(); Console.Write("Merge:\t\t");
                foreach (string s in strings) { Console.Write(s + " "); }

                strings = stringsDefault.ToList();
                strings.SortExtend(ref strings, ArrayExtension.Order.Ascending, ArrayExtension.Algorithm.Quick, new IComparer());
                Console.WriteLine(); Console.Write("Quick:\t\t");
                foreach (string s in strings) { Console.Write(s + " "); }

                strings = stringsDefault.ToList();
                strings.SortExtend(ref strings, ArrayExtension.Order.Ascending, ArrayExtension.Algorithm.Heap, new IComparer());
                Console.WriteLine(); Console.Write("Pyramidal:\t");
                foreach (string s in strings) { Console.Write(s + " "); }

            }catch (ArgumentNullException e) { Console.WriteLine(e.Message); }

            Console.WriteLine();
        }
    }
}




































//public static void SortExtend<T>(this ICollection<T> _, ref List<T> values, Order sorting, Algorithm algorithm)
//{
//    Console.WriteLine("2");
//}


//            List<string>buf = new List<string>() {  "22", "1", "333",  "4444", "666666", "55555", "88888888", "7777777" };   