import java.io.BufferedReader;
import java.io.IOException;

public class Lexer {
    private BufferedReader reader;
    private int currentChar;

    public Lexer(BufferedReader reader) {
        this.reader = reader;
    }

    public String parse() throws IOException {
        StringBuilder sb = new StringBuilder();

        sb.append("[ ");

        int total = 0;

        while (true) {
            this.seek();
            Token<TokenType, TokenValue> token = nextToken();
            if (token != null) {
                if (total > 0) {
                    sb.append(", ");
                }
                sb.append(token);
                total += 1;
            } else break;
        }

        sb.append(" ]");

        return sb.toString();
    }

    private void nextChar() throws IOException {
        currentChar = reader.read();
    }

    public void seek() throws IOException {
        currentChar = reader.read();
        while (Character.isSpaceChar(currentChar)) {
            currentChar = reader.read();
        }
    }

    public Token<TokenType, TokenValue> nextToken() throws IOException {
        if (Character.isDigit(currentChar)) {
            return getNumber();
        } else if (Character.isAlphabetic(currentChar)) {
            return getIdentifier();
        }  else if (currentChar != -1) {
            return getOperator();
        }

        // EOF
        return null;
    }

    private Token<TokenType, TokenValue> getIdentifier() throws IOException {
        StringBuilder readResult = new StringBuilder();

        while (Character.isAlphabetic(currentChar)) {
            readResult.append((char)currentChar);
            nextChar();
        }

        return new Token<>(TokenType.IDENT, new TokenValue(readResult.toString()));
    }

    private Token<TokenType, TokenValue> getOperator() throws IOException {
        StringBuilder readResult = new StringBuilder();
        readResult.append(currentChar);

        switch (currentChar) {
            case '+' -> {
                return new Token<>(TokenType.OP_ADD, new TokenValue("+"));
            }
            case '-' -> {
                return new Token<>(TokenType.OP_NEG, new TokenValue("-"));
            }
            case '*' -> {
                return new Token<>(TokenType.OP_MUL, new TokenValue("*"));
            }
            case '/' -> {
                return new Token<>(TokenType.OP_DIV, new TokenValue("/"));
            }
            case '~' -> {
                return new Token<>(TokenType.OP_NOT, new TokenValue("~"));
            }
            case '&' -> {
                return new Token<>(TokenType.OP_AND, new TokenValue("& "));
            }
            case '|' -> {
                return new Token<>(TokenType.OP_OR, new TokenValue("|"));
            }
        }

        return null;
    }

    private Token<TokenType, TokenValue> getNumber() throws IOException {
        StringBuilder readResult = new StringBuilder();

        while (Character.isDigit(currentChar)) {
            readResult.append(currentChar);
            nextChar();
        }

        if (currentChar == '.') {
            nextChar();
            while (Character.isDigit(currentChar)) {
                readResult.append(currentChar);
                nextChar();
            }

            return new Token<>(TokenType.NUMBER, new TokenValue(Double.parseDouble(readResult.toString())));
        }

        return null;
    }
}
