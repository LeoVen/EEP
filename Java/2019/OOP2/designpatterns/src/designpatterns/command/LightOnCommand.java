package designpatterns.command;

//Concrete Command
public class LightOnCommand implements Command {

    Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    public void execute() {
        light.switchOn();
        System.out.println("Liguei a luz");
    }
}
