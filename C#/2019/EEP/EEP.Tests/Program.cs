using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EEP.Tests.Training;
using System.Speech.Synthesis;
using System.Globalization;
using System.Threading;

namespace EEP.Tests
{
    class Program
    {
        static void WriteAsBytes(int value)
        {
            byte[] bytes = BitConverter.GetBytes(value);

            foreach (byte b in bytes)
            {
                Console.Write("0x{0:X2} ", b);
            }
        }

        static void Main(string[] args)
        {
            // Cultures
            CultureInfo enUS = new CultureInfo("en-US");
            CultureInfo enGB = new CultureInfo("en-GB");
            CultureInfo frFR = new CultureInfo("fr-FR");
            CultureInfo deDE = new CultureInfo("de-DE");

            // Change in current thread's culture
            // Now floating point numbers will be written with dot separators
            Thread.CurrentThread.CurrentCulture = enUS;

            using (SpeechSynthesizer synthesizer = new SpeechSynthesizer())
            {
                synthesizer.Rate = -2;

                // Changing current voice by getting different cultures
                // Get installed voices
                var voices = synthesizer.GetInstalledVoices(enUS);

                if (voices.Count > 0)
                {
                    // Speak!
                    synthesizer.SelectVoice(voices[0].VoiceInfo.Name);
                    synthesizer.Speak(@"Three Rings for the Elven-kings under the sky,
                                        Seven for the Dwarf-lords in their halls of stone,
                                        Nine for Mortal Men doomed to die,
                                        One for the Dark Lord on his dark throne
                                        In the Land of Mordor where the Shadows lie.
                                        One Ring to rule them all, One Ring to find them,
                                        One Ring to bring them all, and in the darkness bind them,
                                        In the Land of Mordor where the Shadows lie.
                                        ");
                }

                // Show installed voices
                Console.WriteLine("Installed Voices");
                foreach (var v in synthesizer.GetInstalledVoices().Select(v => v.VoiceInfo))
                {
                    Console.WriteLine("Name:{0}, Gender:{1}, Age:{2}", v.Description, v.Gender, v.Age);
                }
            }

            Console.Write("How many hours of sleep did you have? > ");

            try
            {
                int hours = Int32.Parse(Console.ReadLine());

                if (hours >= 12)
                {
                    Console.WriteLine("You slept for too much time!");
                }
                else if (hours >= 8)
                {
                    Console.WriteLine("Good. You had enough time to sleep!");
                }
                else
                {
                    Console.WriteLine("You need more time to sleep");
                }

            }
            catch (FormatException e)
            {
                Console.WriteLine("You didn't type a number...");
            }

            GradeBook grades = new GradeBook();

            grades.NameChanged += new NameChangedDelegate(OnNameChange);
            grades.NameChanged += new NameChangedDelegate(OnNameChangeConcat);

            grades.Name = "California";
            grades.Name = "New York";

            grades.NameChanged -= OnNameChangeConcat;

            grades.NameChanged += OnNameChange;
            grades.NameChanged += OnNameChangeConcat;

            grades.Name = "North Carolina";

            grades.AddGrade(new Grade(9.2, 8.6, 7.1, 7.3, 6.2));
            grades.AddGrade(new Grade(10.0, 9.3, 5.4, 5.1, 4.5));
            grades.AddGrade(new Grade(7.8, 7.5, 6.9, 6.3, 10.0));

            Console.WriteLine(grades);

            var GS = new GradeStatistics(grades);

            GS.Compute();

            Console.WriteLine($"Maximum Grade: {GS.Maximum}\nMinimum Grade: {GS.Minimum}\nAverage: {GS.Average}");

            WriteAsBytes(365);

            Console.WriteLine();

            Console.ReadKey();
        }

        static void OnNameChange(object sender, NameChangedEventArgs args)
        {
            Console.WriteLine($"Grade book changing name from {args.ExistingName} to {args.NewName}");
        }

        static void OnNameChangeConcat(object sender, NameChangedEventArgs args)
        {
            Console.WriteLine($"Concat {args.ExistingName}{args.NewName}");
        }
    }
}
