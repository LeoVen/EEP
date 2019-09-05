package designpatterns.proxy;

import java.io.IOException;

public class CommandExecutorImpl implements CommandExecutor {

    protected CommandExecutorImpl() {
    }

    @Override
    public void runCommand(String cmd) throws IOException {
        //some heavy implementation
        //Runtime.getRuntime().exec(cmd);
        System.out.println("'" + cmd + "' command executed.");
    }
}
