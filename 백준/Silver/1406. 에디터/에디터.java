import java.io.*;
import java.util.*;

// linkedList + listIterator 활용
// 기존 linkedlist으로만 구현 시 시간초과
// listIterator : iterator 상속 인터페이스 (iterator 위치를 양방향으로 알수 있는 기능이 있다.)

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str[] = br.readLine().split("");
		int M = Integer.parseInt(br.readLine());
		
		LinkedList<String>list = new LinkedList<>();
		for (String s : str)
		{
		    list.add(s);
		}
		
		ListIterator <String> iter = list.listIterator();
		while(iter.hasNext()) {
		    iter.next();
		}
		
		for (int i = 0; i < M; i++)
		{
		    String[] input = br.readLine().split(" ");
		    
		    if (input[0].charAt(0) == 'L')
		    {
		        if (iter.hasPrevious()) iter.previous();
		    }
		    else if (input[0].charAt(0) == 'D')
		    {
		        if (iter.hasNext()) iter.next();
		    }
		    else if (input[0].charAt(0) == 'B')
		    {
		        if (iter.hasPrevious())
		        {
		            iter.previous();
		            iter.remove();
		        }
		    }
		    else if (input[0].charAt(0) == 'P') iter.add(input[1]);
		}
		System.out.println(String.join("", list));
// 		int cursor = str.length();
// 		for(int i = 0; i < M; i++)
// 		{
// 		    String[] input = br.readLine().split(" ");

// 		    if (input[0].charAt(0) == 'L')
// 		    {
// 		        if (cursor != 0) cursor--;
// 		    }
// 		    else if (input[0].charAt(0) == 'D')
// 		    {
// 		        if (cursor != list.size()) cursor++;
// 		    }
// 		    else if (input[0].charAt(0) == 'B')
// 		    {
// 		        if (cursor != 0)
// 		        {
// 		            list.remove(--cursor);
// 		        }
// 		    }
// 		    else if (input[0].charAt(0) == 'P')
// 		    {
// 		        char c = input[1].charAt(0);
// 		        list.add(cursor, c);
// 		        cursor++;
// 		    }
// 		}
		
// 		for (char data : list)
// 		    System.out.print(data);
	}
}