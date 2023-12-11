using Ex4;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex4
{

    internal class Program
    {

        static Stopwatch stopwatch = new Stopwatch();
        static void Main(string[] args)
        {
            try
            {
                double
                        a = -100,
                        b = 1,
                        accur = 1E-04;

                stopwatch.Start(); ToConsole($"Left:\t\t{new IntegerLeftRectangles().Count(Function, a, b, accur)}");
                stopwatch.Start(); ToConsole($"Right:\t\t{new IntegerRightRectangles().Count(Function, a, b, accur)}");
                stopwatch.Start(); ToConsole($"Middle:\t\t{new IntegerMiddleRectangles().Count(Function, a, b, accur)}");
                stopwatch.Start(); ToConsole($"Trapeze:\t{new IntegerTrapeze().Count(Function, a, b, accur)}");
                stopwatch.Start(); ToConsole($"Simpsons:\t{new IntegerSimpson().Count(Function, a, b, accur)}");
            }
            catch (ArgumentNullException e) { Console.WriteLine(e.Message); }
            catch (ArgumentException e) { Console.WriteLine(e.Message); }

        }
        public static double Function(double x)
        {
            return Math.Exp(x);
        }


        public static void ToConsole(string text, string tb="\t")
        { 
            Console.Write(text);
            stopwatch.Stop();
            Console.Write($"\t({stopwatch.ElapsedMilliseconds} ms)");
            Console.WriteLine();
            stopwatch.Reset();
        }
    }
}