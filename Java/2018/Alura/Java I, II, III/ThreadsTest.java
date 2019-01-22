/*
 *
 * Testando array de Threads
 *
 */

public class ThreadsTest {
    public static void main(String[] args) {

    	int j = 300;
    	Program[] list = new Program[j];
    	Thread[] threads = new Thread[j];

		for (int i = 0; i < 100; i++) {

			list[i] = new Program();
			list[i].setId(i);
			threads[i] = new Thread(list[i]);
			threads[i].start();

		}

    }
}

class Program implements Runnable {

    private int id;           
    
    public void setId(int id) {
    	this.id = id;
    }

    public void run () {
        for (int i = 0; i < 10000; i++) {
            System.out.println("Programa " + id + " valor: " + i);
        }
    }
}