using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.Training
{
    public class NameChangedEventArgs
    {
        public string ExistingName { get; set; }
        public string NewName { get; set; }

        public NameChangedEventArgs(string existingName, string newName)
        {
            ExistingName = existingName;
            NewName = newName;
        }
    }
}
