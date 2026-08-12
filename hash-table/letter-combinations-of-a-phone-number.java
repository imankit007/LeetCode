class Solution {
    public void CreateMapping(HashMap<Character, List<Character>> DigitCharList) {
        ArrayList<Character> listofchars = new ArrayList<>();
        listofchars.add('a');
        listofchars.add('b');
        listofchars.add('c');
        DigitCharList.put('2', listofchars);
        ArrayList<Character> listofchars2 = new ArrayList<>();
        listofchars2.add('d');
        listofchars2.add('e');
        listofchars2.add('f');
        DigitCharList.put('3', listofchars2);
        ArrayList<Character> listofchars3 = new ArrayList<>();
        listofchars3.add('g');
        listofchars3.add('h');
        listofchars3.add('i');
        DigitCharList.put('4', listofchars3);
        ArrayList<Character> listofchars4 = new ArrayList<>();
        listofchars4.add('j');
        listofchars4.add('k');
        listofchars4.add('l');
        DigitCharList.put('5', listofchars4);
        ArrayList<Character> listofchars5 = new ArrayList<>();
        listofchars5.add('m');
        listofchars5.add('n');
        listofchars5.add('o');
        DigitCharList.put('6', listofchars5);
        ArrayList<Character> listofchars6 = new ArrayList<>();
        listofchars6.add('p');
        listofchars6.add('q');
        listofchars6.add('r');
        listofchars6.add('s');
        DigitCharList.put('7', listofchars6);
        ArrayList<Character> listofchars7 = new ArrayList<>();
        listofchars7.add('t');
        listofchars7.add('u');
        listofchars7.add('v');
        DigitCharList.put('8', listofchars7);
        ArrayList<Character> listofchars8 = new ArrayList<>();
        listofchars8.add('w');
        listofchars8.add('x');
        listofchars8.add('y');
        listofchars8.add('z');
        DigitCharList.put('9', listofchars8);
    }

    public List<String> letterCombinations(String digits) {
        HashMap<Character, List<Character>> DigitCharList = new HashMap<>();
        CreateMapping(DigitCharList);
        // System.out.println(DigitCharList);
        ArrayList<String> listofstrings = new ArrayList<>();
        for (int t = 0; t < digits.length(); t++) {
            char curchar = digits.charAt(t);
            if (DigitCharList.containsKey(curchar)) {
                List<Character> list = DigitCharList.get(curchar);
                if (listofstrings.size() == 0) {
                    for (int i = 0; i < list.size(); i++) {
                        String str = String.valueOf(list.get(i));
                        listofstrings.add(str);
                    }
                } else {
                    ArrayList<String> newlistofstrings = new ArrayList<>();
                    for (int j = 0; j < listofstrings.size(); j++) {
                        String existingStr = listofstrings.get(j);
                        for (int i = 0; i < list.size(); i++) {
                            String str = existingStr + String.valueOf(list.get(i));
                            newlistofstrings.add(str);
                        }
                    }
                    listofstrings = newlistofstrings;
                }
            }
        }
        return listofstrings;

    }

}