package designpatterns.factorymethod;

public abstract class Pessoa {

    public static final String HOMEM = "M";
    public static final String MULHER = "F";
    private String nome;

    protected Pessoa(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public abstract String getTratamento();

}
