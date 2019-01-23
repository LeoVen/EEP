using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.DataStructures.Lists
{
    public class ArrayLinkedList<T> : IEnumerable<T>
    {
        public ArrayList<T> ReferenceList = new ArrayList<T>();

        public DoublyLinkedList<T> List = new DoublyLinkedList<T>();

        public int Count { get; set; }

        public T this[int index]
        {
            get
            {
                if (index < 0 || index >= Count) throw new IndexOutOfRangeException(nameof(index));
                return ReferenceList[index];
            }
            set
            {
                if (index < 0 || index >= Count) throw new IndexOutOfRangeException(nameof(index));
                ReferenceList[index] = value;
            }
        }

        public ArrayLinkedList()
        {
            Count = 0;
        }

        public ArrayLinkedList(int capacity)
        {
            ReferenceList = new ArrayList<T>(capacity);

            List = new DoublyLinkedList<T>();
        }

        public void Add(T element)
        {
            ReferenceList.Add(element);
            List.AddLast(element);
        }
        
        public void Regenerate()
        {
            ReferenceList.Clear();
            ReferenceList = new ArrayList<T>(List);
        }
        
        public IEnumerator<T> GetEnumerator()
        {
            return List.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return List.GetEnumerator();
        }
    }
}
