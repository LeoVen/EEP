import java.io.BufferedReader;
import java.io.FileReader;

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Please provide a file name to be parsed");
        }

        try {
            String fileName = args[0];
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            Lexer lexer = new Lexer(reader);

            String result = lexer.parse();

            System.out.println(result);
        } catch (Exception e)  {
            System.err.println("Failed to read file.");
            e.printStackTrace();
        }
    }
}
