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
        static void Main(string[] args)
        {
            using (SpeechSynthesizer synthesizer = new SpeechSynthesizer())
            {
				synthesizer.Rate = -2;
				
                var voices = synthesizer.GetInstalledVoices(new CultureInfo("en-US"));

                if (voices.Count > 0)
                {
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
            }
        }
    }
}
