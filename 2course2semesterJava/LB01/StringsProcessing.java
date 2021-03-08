package com.company;

public class StringsProcessing {
    public static String smallest(String[] strings) {
        if(strings==null)
        {
            return "-";
        }
        String smallest = strings[0];
        for (String element: strings) {
            if (element.length() < smallest.length()) {
                smallest = element;
            }
        }
        return smallest;
    }
}