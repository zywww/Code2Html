package Tools;

import java.io.File;

public class ExtensionFilter implements java.io.FileFilter{
    String extensions[];
    public ExtensionFilter(String extensions[]){
        this.extensions = new String[extensions.length];
        for(int i = 0; i < extensions.length; i++){
            this.extensions[i] = extensions[i].toLowerCase();
        }
    }

    public boolean accept(File pathname){
        if(pathname.isDirectory()){
            return true;
        }
        String name = pathname.getName().toLowerCase();
        for(int i = 0; i < extensions.length; i++){
            if(name.endsWith(this.extensions[i])){
                return true;
            }
        }
        return false;
    }
}