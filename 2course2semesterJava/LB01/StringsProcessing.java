package com.company;

public class StringsProcessing {
    public String smallest(String[] strings) {
        if(strings==null)
        {
            return "-";
        }
        String smallest = strings[0];
        for (int i = 1; i < strings.length; ++i) {
            if (strings[i].length() < smallest.length()) {
                smallest = strings[i];
            }
        }
        return smallest;
    }
}