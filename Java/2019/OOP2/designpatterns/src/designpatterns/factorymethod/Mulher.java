package designpatterns.factorymethod;

public class Mulher extends Pessoa {

    public Mulher(String nome) {
        super(nome);
        System.out.println("Olá, " + getTratamento() + " " + getNome());
    }

    @Override
    public String getTratamento() {
        return "Senhora";
    }

}
