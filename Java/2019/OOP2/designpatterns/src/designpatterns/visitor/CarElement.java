package designpatterns.visitor;

public interface CarElement {

    void accept(CarElementVisitor visitor);
}
