package designpatterns.factorymethod;

public class Teste {

    public static void main(String args[]) {
        FactoryPessoa factory = new FactoryPessoa();
        factory.getPessoa("Carla", "F");
        factory.getPessoa("Carlos", "M");
    }
}
