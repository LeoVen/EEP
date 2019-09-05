package designpatterns.factorymethod;

public class Homem extends Pessoa {

    public Homem(String nome) {
        super(nome);
        System.out.println("Olá, " + getTratamento() + " " + getNome());
    }

    @Override
    public String getTratamento() {
        return "Senhor";
    }

}
