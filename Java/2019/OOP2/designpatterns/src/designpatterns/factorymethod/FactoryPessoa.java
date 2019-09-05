package designpatterns.factorymethod;

public class FactoryPessoa {

    public Pessoa getPessoa(String nome, String sexo) {
        if (sexo.equals(Pessoa.HOMEM)) {
            return new Homem(nome);
        }
        if (sexo.equals(Pessoa.MULHER)) {
            return new Mulher(nome);
        }
        return null;
    }
}
