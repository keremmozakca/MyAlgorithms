import java.util.*;

class Solution {
    Stack<String> st = new Stack<String>();
    String[] Paranthesis1 = {"(", ")"};
    String[] Paranthesis2 = {"{", "}"};
    String[] Paranthesis3 = {"[", "]"};
    char[] a;

    public boolean isValid(String s) {
        if (s == null || s.length() == 0) {
            return true; // Boş stringi geçerli kabul edin
        }

        a = s.toCharArray();

        // Eğer ilk karakter kapalı parantez ise geçersizdir
        if (closedBy(String.valueOf(a[0])) != 0) {
            return false;
        }

        st.push(String.valueOf(a[0]));
        String[] l = which(String.valueOf(a[0]));

        for (int i = 1; i < s.length(); i++) {
            String value = String.valueOf(a[i]);
            if (l != null && closedBy(l[1]) == closedBy(value)) {
                st.pop();
                if (st.isEmpty()) {
                    l = null;
                } else {
                    l = which(st.peek());
                }
            } else if (closedBy(value) == 0) {
                st.push(value);
                l = which(value);
            }else{
                return false;
            }
        }
        return st.isEmpty();
    }

    public String[] which(String a) {
        if (a.equals("(")) {
            return Paranthesis1;
        }
        if (a.equals("{")) {
            return Paranthesis2;
        }
        if (a.equals("[")) {
            return Paranthesis3;
        }
        return null;
    }

    public int closedBy(String s) {
        if (s.equals(")")) {
            return 1;
        } else if (s.equals("}")) {
            return 2;
        } else if (s.equals("]")) {
            return 3;
        } else {
            return 0;
        }
    }
}
