

public class Token<Ttype extends TokenType, Tvalue extends TokenValue> {
    Ttype tokenType;
    Tvalue tokenValue;

    public Token(Ttype tokenType, Tvalue tokenValue) {
        this.tokenType = tokenType;
        this.tokenValue = tokenValue;
    }

    @Override
    public String toString() {
        return "Token [" + tokenType +
                ", " + tokenValue +
                "]";
    }
}
