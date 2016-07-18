package ConvertCode;

import java.awt.Color;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import GUI.Code2HtmlGUI;
import Tools.ExtensionFilter;

public class ConverCode2Html {
	public static int taskNum = 0;
	
	public static int done = 0;
	
	public static int value = 0;
	
	//全部关键字
	static String[] JavaKeywordString = {
	    "abstract", "assert", "boolean",
	    "break", "byte", "case", "catch", "char", "class", "const",
	    "continue", "default", "do", "double", "else", "enum",
	    "extends", "for", "final", "finally", "float", "goto", "if",
	    "implements", "import", "instanceof", "int", "interface",
	    "long", "native", "new", "package", "private", "protected",
	    "public", "return", "short", "static", "strictfp", "super",
	    "switch", "synchronized", "this", "throw", "throws",
	    "transient", "try", "void", "volatile", "while",
	    "true", "false", "null"};

	static Set<String> JavaKeywordSet =
	    new HashSet<String>(Arrays.asList(JavaKeywordString));
	
	static String[] CKeywordString = {
		"auto", "break", "case", "char", "const", "continue",
		"default", "do", "double", "else", "enum", "extern",
		"float", "for", "goto", "if", "int", "long",
		"register", "return", "short", "signed", "sizeof", "static",
		"struct", "switch", "typedef", "union", "unsigned", "void",
		"volatile", "while"
	};
	
	static Set<String> CKeywordSet = 
		new HashSet<String>(Arrays.asList(CKeywordString));
	
	static String[] CppKeywordString = {
		"asm", "do", "if", "return", "typedef", "auto",
		"double", "inline", "short", "typeid", "bool", "dynamic_cast",
		"int", "signed", "typename", "break", "else", "long", 
		"sizeof", "union", "case", "enum", "mutable", "static", 
		"unsigned", "catch", "explicit", "namespace", "static_cast", "using", 
		"char", "export", "new", "struct", "virtual", "class",
		"extern", "operator", "switch", "void", "const", "false", 
		"private", "template", "volatile", "const_cast", "float", "protected",
		"this", "wchar_t", "continue", "for", "public", "throw",
		"while", "default", "friend", "register", "true", "delete", 
		"goto", "reinterpret_cast", "try", "alignas", "alignof", "char16_t",
		"char32_t", "constexpr", "decltype", "noexcept", "nullptr", "static_assert",
		"thread_local"
	};
	
	static Set<String> CppKeywordSet = 
		new HashSet<String>(Arrays.asList(CppKeywordString));
	
	static String[] JsKeywordString = {
		"break", "case", "catch", "continue", "default", "delete",
		"do", "else", "finally", "for", "function", "if",
		"in", "instanceof", "new", "return", "switch", "this",
		"throw", "try", "typeof", "var", "void", "while",
		"with", "class", "enum", "export", "extends", "implements",
		"import", "interface", "package", "private", "protected", "static",
		"super"
	};
	
	static Set<String> JsKeywordSet = 
			new HashSet<String>(Arrays.asList(JsKeywordString));
	
	static Set<String> ClassSet = new HashSet<String>();
	  
	static boolean stringToken = false;
	
	//public static String codeType;
	
	public static String[] colors = new String[4];
	
	public static String fontType;
	
	public static String fontSize;
	
	public static File sourceFile;
	
	public static File folder;
	
	public static void convert(Color[] newColors, String newFontType,
			String newFontSize,  File newSourceFile, String newConvertTo) {
		
		for (int i = 0; i < 4; i++) {
			colors[i] = "#" + getHexString(newColors[i].getRed()) +
					getHexString(newColors[i].getGreen()) +
					getHexString(newColors[i].getBlue());
		}
		
		
		
		fontType = newFontType;
		
		fontSize = newFontSize;
		
		folder = new File(newConvertTo);
		
		sourceFile = newSourceFile;
		try {
			if (sourceFile.getName().endsWith(".java")) {
				File classFile[] = sourceFile.getParentFile().listFiles(new ExtensionFilter(new String[]{".java"}));
				for (int i = 0; i < classFile.length; i++) {
					if (classFile[i].isFile() && !classFile[i].equals(sourceFile)) {
						String className = classFile[i].getName();
						ClassSet.add(className.substring(0, className.lastIndexOf(".")));
						
					}
				}
				
				java2Html();
				
				ClassSet.clear();
			}
			else if (sourceFile.getName().endsWith(".c")) {
			
				c2Html();
			}
			else if (sourceFile.getName().endsWith(".cpp") || sourceFile.getName().endsWith(".h")) {
				cpp2Html();
			}
			else if (sourceFile.getName().endsWith(".js")) {
				js2Html();
			
			}
			} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	  
	public static void java2Html() throws FileNotFoundException {
		Scanner input = new Scanner(sourceFile);
		
		File targetFile = new File(folder.getAbsolutePath() + "\\" + 
				sourceFile.getName() + ".html");
		PrintWriter output = new PrintWriter(targetFile);
		
		
		
		output.format("%s\r\n", "<!DOCTYPE HTML>");
		output.format("%s\r\n", "<html>");
	    output.format("%s\r\n", "<head>");
	    output.format("%s\r\n", "<title>" + sourceFile.getName() + "</title>");
	    output.format("%s\r\n", "<style type = \"text/css\">");
	   
	    output.format("%s\r\n", ".orderList {");
	    output.format("%s\r\n", "tab-size:4;");
	    output.format("%s\r\n", "font-family: " + fontType + ", \"Courier New\", Courier, mono, serif;");
	    if (fontSize.equals("small")) {
	    	output.format("%s\r\n", "font-size: 12px;");
	    }
	    else
	    	output.format("%s\r\n", "font-size: " + fontSize + ";"); 
	    output.format("%s\r\n", "background-color: #E7E5DC;");
	    output.format("%s\r\n", "width: 96%;");
	    output.format("%s\r\n", "overflow: auto;");
	    output.format("%s\r\n", "margin: 18px 0 18px 0 !important;");
	    output.format("%s\r\n", "padding-left: 45px;");
	    output.format("%s\r\n", "padding-top: 1px;}");
	    output.format("%s\r\n", "li { list-style: decimal-leading-zero;");
	    output.format("%s\r\n", "list-style-position: outside !important;");
	    output.format("%s\r\n", "border-left: 3px solid #6CE26C;");
	    output.format("%s\r\n", "background-color: #F8F8F8;");
	    output.format("%s\r\n", "color: #5C5C5C;");
	    output.format("%s\r\n", "padding: 0 3px 0 10px !important;");
	    output.format("%s\r\n", "margin: 0 !important;");
	    output.format("%s\r\n", "line-height: 14px; }");
	    output.format("%s\r\n", "span {");
	    output.format("%s\r\n", "color: " + colors[3] + ";}");
	    output.format("%s\r\n", ".keyword {color: " + colors[0] + "; font-weight: bold;}");
	    output.format("%s\r\n", ".comment {color: " + colors[1] + ";}");
	    output.format("%s\r\n", ".literal {color: " + colors[2] + ";}");
	    output.format("%s\r\n", "#backToTop {");
	    output.format("%s\r\n", "position: fixed; bottom: 50px; right: 70px;}");
	    
	    output.format("%s\r\n", "</style>");
	    output.format("%s\r\n", "</head>");
	    output.format("%s\r\n", "<body>");
	    output.format("%s\r\n", "<div class=\"sourceCode\">");
	    output.format("%s\r\n", "<div>");
	    output.format("%s\r\n", "<div class=\"tools\"></div>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<pre>");
	    output.format("%s", "<ol class=\"orderList\">");
	   
	    StringBuilder textTemp = new StringBuilder("");
	    String text = "";
	    String temp;
	    
	    // Read all lines
	    while (input.hasNext()) {
	      temp = input.nextLine();
	      text += temp + "\r\n";
	    }

	    text = text.replaceAll(">", "&gt;");
	    text = text.replaceAll("<", "&lt;");
	    
	    text = text.replaceAll("//", "LINECOMMENT");
	    text = text.replaceAll("/\\*", "BLOCKCOMMENT");
	    

long length = text.length();
//int value = 0;
	    
	    
	    String token;

	    while (text != null && text.length() > 0) {
	    	
	      //利用正则表达式将文本分出一个单词
	       String[] parts = text.split("[%\\+\\-\\*/\r\n\t \\[\\].(){},\\?:\\!=~|^;]", 2);
	       
value = (int)((1.0 * done / taskNum + (1.0 - 1.0 * parts[1].length() / length) / taskNum) * 10000);
	       
	  //     Code2HtmlGUI.progressbar.setValue(value);
	       
	       token = parts[0];
	      //行注释
	      if (token.length() > 1 && token.startsWith("LINECOMMENT")) {
	    	textTemp.append("<span class = \"comment\">");
	        parts = text.split("\r\n", 2);
	        text = parts[1];
	        textTemp.append(parts[0].replaceAll("LINECOMMENT", "// "));
	        textTemp.append("</span>\r\n");
	        continue;
	      }
	      //块注释
	      else if (token.length() > 1 && token.startsWith("BLOCKCOMMENT")) {
	    	//textTemp.append("<span class = \"comment\">");
	        parts = text.split("\\*/", 2);
	        text = parts[1];
	        
	        String temp1[] = parts[0].split("\r\n");
	        for (int i = 0; i < temp1.length - 1; i++) {
	        	textTemp.append("<span class = \"comment\">" + 
	        	temp1[i].replaceAll("BLOCKCOMMENT", "/*") + "</span>\r\n");
	        }
	        textTemp.append("<span class = \"comment\">" + 
		      temp1[temp1.length - 1].replaceAll("BLOCKCOMMENT", "/*") + "*/" + "</span>\r\n");
	        continue;
	      }
	      //直接量
	      //token正好为"xxx"的情况
	      else if (token.startsWith("\"") && token.endsWith("\"") &&
	               (token.length() > 1)) {
	    	 textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token正好为'xxx'的情况
	      else if (token.startsWith("'") && token.endsWith("'") &&
	               (token.length() > 1)) {
	    	textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token为一个"号的情况,而stringToken判断"号是前面的还是后面的"号
	      else if (token.equals("\"")) {
	        if (stringToken) {
	          textTemp.append(token + "</span>");
	          stringToken = false;
	        }
	        else {
	          textTemp.append("<span class = \"literal\">" + token);
	          stringToken = true;
	        }
	      }
	      else if (token.startsWith("\"")) {
	    	textTemp.append("<span class = \"literal\">" + token);
	        stringToken = true;
	      }
	      else if (token.endsWith("\"") && (!token.endsWith("\\\""))) {
	    	  textTemp.append(token);
	    	  textTemp.append("</span>");
	    	  stringToken = false;
	      }
	      else if (token.matches("\\d+")) { // Check if numeric
	    	  textTemp.append("<span class = \"literal\">" + token +
	                      "</span>");
	      }
	      else if (!stringToken && JavaKeywordSet.contains(token)) {
	    	  textTemp.append("<span class = \"keyword\">" + token +
	                      "</span>");
	      }
	      else if (!stringToken && ClassSet.contains(token)) {
	    	  textTemp.append("<a href=\"" + folder + "/" + token + ".java.html\">" + token + "</a>");
	      }
	      else {
	    	  textTemp.append(token);
	      }

	      if (token.length() < text.length()) {
	        if (text.charAt(token.length()) == '<')
	        	textTemp.append("&lt;");
	        else if (text.charAt(token.length()) == '>')
	        	textTemp.append("&gt;");
	        else
	        	textTemp.append(text.charAt(token.length()));
	      }

	      if (parts.length == 2) {
	        text = parts[1];
	      }
	      
	    }
	    
	    
	    String line[] = textTemp.toString().split("\r\n");
	    for (int i = 0; i < line.length; i++) {
	    	output.format("%s", "<li>" + "<span>" + line[i] + "</span>" + "</li>");
	    }
	    
  
	    output.format("%s\r\n", "</ol>");
	    output.format("%s\r\n", "</pre>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<a id=\"backToTop\" href=\"#top\">");
	    output.format("%s", "<img src=\"" + new File("top.png").getAbsolutePath() + "\"");
	    output.format("%s", "onerror=\"nofind();\"");
	    output.format("%s", " width=\"48\" alt=\"Back to top\" title=\"Back to top\">");
	    output.format("%s\r\n", "</a>");
	    output.format("%s\r\n", "<script type=\"text/javascript\">");
	    output.format("%s\r\n", "function nofind(){");
	    output.format("%s\r\n", "var img=event.srcElement;");
	    output.format("%s\r\n", "img.src=\"http://www.easyicon.net/api/resize_png_new.php?id=1180466&size=48\"; ");
	    output.format("%s\r\n", "img.onerror=null;}");
	    output.format("%s\r\n", "</script>");
	    output.format("%s\r\n", "</body>");
	    output.format("%s\r\n", "</html>");
	    
	    File file = new File("");
	    
	    
	    input.close();
        output.close();
        
		
	}
	
	public static void c2Html() throws FileNotFoundException {
		Scanner input = new Scanner(sourceFile);
		
		File targetFile = new File(folder.getAbsolutePath() + "\\" + 
				sourceFile.getName() + ".html");
		PrintWriter output = new PrintWriter(targetFile);
		
		
		
		output.format("%s\r\n", "<!DOCTYPE HTML>");
		output.format("%s\r\n", "<html>");
	    output.format("%s\r\n", "<head>");
	    output.format("%s\r\n", "<title>" + sourceFile.getName() + "</title>");
	    output.format("%s\r\n", "<style type = \"text/css\">");
	   
	    output.format("%s\r\n", ".orderList {");
	    output.format("%s\r\n", "tab-size:4;");
	    output.format("%s\r\n", "font-family: " + fontType + ", \"Courier New\", Courier, mono, serif;");
	    if (fontSize.equals("small")) {
	    	output.format("%s\r\n", "font-size: 12px;");
	    }
	    else
	    	output.format("%s\r\n", "font-size: " + fontSize + ";"); 
	    output.format("%s\r\n", "background-color: #E7E5DC;");
	    output.format("%s\r\n", "width: 96%;");
	    output.format("%s\r\n", "overflow: auto;");
	    output.format("%s\r\n", "margin: 18px 0 18px 0 !important;");
	    output.format("%s\r\n", "padding-left: 45px;");
	    output.format("%s\r\n", "padding-top: 1px;}");
	    output.format("%s\r\n", "li { list-style: decimal-leading-zero;");
	    output.format("%s\r\n", "list-style-position: outside !important;");
	    output.format("%s\r\n", "border-left: 3px solid #6CE26C;");
	    output.format("%s\r\n", "background-color: #F8F8F8;");
	    output.format("%s\r\n", "color: #5C5C5C;");
	    output.format("%s\r\n", "padding: 0 3px 0 10px !important;");
	    output.format("%s\r\n", "margin: 0 !important;");
	    output.format("%s\r\n", "line-height: 14px; }");
	    output.format("%s\r\n", "span {");
	    output.format("%s\r\n", "color: " + colors[3] + ";}");
	    output.format("%s\r\n", ".keyword {color: " + colors[0] + "; font-weight: bold;}");
	    output.format("%s\r\n", ".comment {color: " + colors[1] + ";}");
	    output.format("%s\r\n", ".literal {color: " + colors[2] + ";}");
	    output.format("%s\r\n", ".preprocessor {color: grey;}");
	    output.format("%s\r\n", "#backToTop {");
	    output.format("%s\r\n", "position: fixed; bottom: 50px; right: 70px;}");
	    
	    output.format("%s\r\n", "</style>");
	    output.format("%s\r\n", "</head>");
	    output.format("%s\r\n", "<body>");
	    output.format("%s\r\n", "<div class=\"sourceCode\">");
	    output.format("%s\r\n", "<div>");
	    output.format("%s\r\n", "<div class=\"tools\"></div>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<pre>");
	    output.format("%s", "<ol class=\"orderList\">");
	   
	    StringBuilder textTemp = new StringBuilder("");
	    String text = "";
	    String temp;
	    
	    // Read all lines
	    while (input.hasNext()) {
	      temp = input.nextLine();
	      text += temp + "\r\n";
	    }

	    text = text.replaceAll(">", "&gt;");
	    text = text.replaceAll("<", "&lt;");
	    
	    text = text.replaceAll("//", "LINECOMMENT");
	    text = text.replaceAll("/\\*", "BLOCKCOMMENT");
	    text = text.replaceAll("#", "PREPROCESSOR");
	    
	    long length = text.length();
	    
	    String token;

	    while (text != null && text.length() > 0) {
	    
	    	//利用正则表达式将文本分出一个单词
	    	String[] parts = text.split("[%\\+\\-\\*/\r\n\t \\[\\].(){},\\?:\\!=~|^;]", 2);

	    	value = (int)((1.0 * done / taskNum + (1.0 - 1.0 * parts[1].length() / length) / taskNum) * 10000);
	    	
	       token = parts[0];
	       
	       if (token.length() > 1 && token.startsWith("PREPROCESSOR")) {
	    	   textTemp.append("<span class = \"preprocessor\">");
	    	   parts = text.split("\r\n", 2);
	    	   text = parts[1];
	    	   textTemp.append(parts[0].replaceAll("PREPROCESSOR", "#"));
	    	   textTemp.append("</span>\r\n");
	    	   continue;
	       }
	       //行注释
	       else if (token.length() > 1 && token.startsWith("LINECOMMENT")) {
	    	   textTemp.append("<span class = \"comment\">");
	    	   parts = text.split("\r\n", 2);
	    	   text = parts[1];
	    	   textTemp.append(parts[0].replaceAll("LINECOMMENT", "//"));
	    	   textTemp.append("</span>\r\n");
	    	   continue;
	       }
	       //块注释
	       else if (token.length() > 1 && token.startsWith("BLOCKCOMMENT")) {
	    	   //textTemp.append("<span class = \"comment\">");
	    	   parts = text.split("\\*/", 2);
	    	   text = parts[1];
	        
	    	   String temp1[] = parts[0].split("\r\n");
	    	   for (int i = 0; i < temp1.length; i++) {
	    		   textTemp.append("<span class = \"comment\">" + 
	    					temp1[i].replaceAll("BLOCKCOMMENT", "/*") + "</span>\r\n");
		        }
		        textTemp.append("<span class = \"comment\">" + 
			      temp1[temp1.length - 1].replaceAll("BLOCKCOMMENT", "/*") + "*/" + "</span>\r\n");
	    	   continue;
	       }
	       //直接量
	       //token正好为"xxx"的情况
	       	else if (token.startsWith("\"") && token.endsWith("\"") &&
	    	(token.length() > 1)) {
	    	 textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token正好为'xxx'的情况
	      else if (token.startsWith("'") && token.endsWith("'") &&
	               (token.length() > 1)) {
	    	textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token为一个"号的情况,而stringToken判断"号是前面的还是后面的"号
	      else if (token.equals("\"")) {
	        if (stringToken) {
	          textTemp.append(token + "</span>");
	          stringToken = false;
	        }
	        else {
	          textTemp.append("<span class = \"literal\">" + token);
	          stringToken = true;
	        }
	      }
	      else if (token.startsWith("\"")) {
	    	textTemp.append("<span class = \"literal\">" + token);
	        stringToken = true;
	      }
	      else if (token.endsWith("\"") && (!token.endsWith("\\\""))) {
	    	  textTemp.append(token);
	    	  textTemp.append("</span>");
	    	  stringToken = false;
	      }
	      else if (token.matches("\\d+")) { // Check if numeric
	    	  textTemp.append("<span class = \"literal\">" + token +
	                      "</span>");
	      }
	      else if (!stringToken && CKeywordSet.contains(token)) {
	    	  textTemp.append("<span class = \"keyword\">" + token +
	                      "</span>");
	      }
	      else {
	    	  textTemp.append(token);
	      }

	      if (token.length() < text.length()) {
	        if (text.charAt(token.length()) == '<')
	        	textTemp.append("&lt;");
	        else if (text.charAt(token.length()) == '>')
	        	textTemp.append("&gt;");
	        else
	        	textTemp.append(text.charAt(token.length()));
	      }

	      if (parts.length == 2) {
	        text = parts[1];
	      }
	      
	    }
	    
	    
	    String line[] = textTemp.toString().split("\r\n");
	    for (int i = 0; i < line.length; i++) {
	    	output.format("%s", "<li>" + "<span>" + line[i] + "</span>" + "</li>");
	    }
	    
  
	    output.format("%s\r\n", "</ol>");
	    output.format("%s\r\n", "</pre>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<a id=\"backToTop\" href=\"#top\">");
	    output.format("%s", "<img src=\"" + new File("top.png").getAbsolutePath() + "\"");
	    output.format("%s", "onerror=\"nofind();\"");
	    output.format("%s", " width=\"48\" alt=\"Back to top\" title=\"Back to top\">");
	    output.format("%s\r\n", "</a>");
	    output.format("%s\r\n", "<script type=\"text/javascript\">");
	    output.format("%s\r\n", "function nofind(){");
	    output.format("%s\r\n", "var img=event.srcElement;");
	    output.format("%s\r\n", "img.src=\"http://www.easyicon.net/api/resize_png_new.php?id=1180466&size=48\"; ");
	    output.format("%s\r\n", "img.onerror=null;}");
	    output.format("%s\r\n", "</script>");
	    output.format("%s\r\n", "</body>");
	    output.format("%s\r\n", "</html>");
	    
	    input.close();
        output.close();
		
	}
	
	public static void cpp2Html() throws FileNotFoundException {
		Scanner input = new Scanner(sourceFile);
		
		File targetFile = new File(folder.getAbsolutePath() + "\\" + 
				sourceFile.getName() + ".html");
		PrintWriter output = new PrintWriter(targetFile);
		
		
		
		output.format("%s\r\n", "<!DOCTYPE HTML>");
		output.format("%s\r\n", "<html>");
	    output.format("%s\r\n", "<head>");
	    output.format("%s\r\n", "<title>" + sourceFile.getName() + "</title>");
	    output.format("%s\r\n", "<style type = \"text/css\">");
	   
	    output.format("%s\r\n", ".orderList {");
	    output.format("%s\r\n", "tab-size:4;");
	    output.format("%s\r\n", "font-family: " + fontType + ", \"Courier New\", Courier, mono, serif;");
	    if (fontSize.equals("small")) {
	    	output.format("%s\r\n", "font-size: 12px;");
	    }
	    else
	    	output.format("%s\r\n", "font-size: " + fontSize + ";"); 
	    output.format("%s\r\n", "background-color: #E7E5DC;");
	    output.format("%s\r\n", "width: 96%;");
	    output.format("%s\r\n", "overflow: auto;");
	    output.format("%s\r\n", "margin: 18px 0 18px 0 !important;");
	    output.format("%s\r\n", "padding-left: 45px;");
	    output.format("%s\r\n", "padding-top: 1px;}");
	    output.format("%s\r\n", "li { list-style: decimal-leading-zero;");
	    output.format("%s\r\n", "list-style-position: outside !important;");
	    output.format("%s\r\n", "border-left: 3px solid #6CE26C;");
	    output.format("%s\r\n", "background-color: #F8F8F8;");
	    output.format("%s\r\n", "color: #5C5C5C;");
	    output.format("%s\r\n", "padding: 0 3px 0 10px !important;");
	    output.format("%s\r\n", "margin: 0 !important;");
	    output.format("%s\r\n", "line-height: 14px; }");
	    output.format("%s\r\n", "span {");
	    output.format("%s\r\n", "color: " + colors[3] + ";}");
	    output.format("%s\r\n", ".keyword {color: " + colors[0] + "; font-weight: bold;}");
	    output.format("%s\r\n", ".comment {color: " + colors[1] + ";}");
	    output.format("%s\r\n", ".literal {color: " + colors[2] + ";}");
	    output.format("%s\r\n", ".preprocessor {color: grey;}");
	    output.format("%s\r\n", "#backToTop {");
	    output.format("%s\r\n", "position: fixed; bottom: 50px; right: 70px;}");
	    
	    output.format("%s\r\n", "</style>");
	    output.format("%s\r\n", "</head>");
	    output.format("%s\r\n", "<body>");
	    output.format("%s\r\n", "<div class=\"sourceCode\">");
	    output.format("%s\r\n", "<div>");
	    output.format("%s\r\n", "<div class=\"tools\"></div>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<pre>");
	    output.format("%s", "<ol class=\"orderList\">");
	   
	    StringBuilder textTemp = new StringBuilder("");
	    String text = "";
	    String temp;
	    
	    // Read all lines
	    while (input.hasNext()) {
	      temp = input.nextLine();
	      text += temp + "\r\n";
	    }

	    text = text.replaceAll(">", "&gt;");
	    text = text.replaceAll("<", "&lt;");
	    
	    text = text.replaceAll("//", "LINECOMMENT");
	    text = text.replaceAll("/\\*", "BLOCKCOMMENT");
	    text = text.replaceAll("#", "PREPROCESSOR");
	    
	    long length = text.length();

	    String token;
	    
	    while (text != null && text.length() > 0) {
	    
	    	//利用正则表达式将文本分出一个单词
	    	String[] parts = text.split("[%\\+\\-\\*/\r\n\t \\[\\].(){},\\?:\\!=~|^;]", 2);
	       
	    	value = (int)((1.0 * done / taskNum + (1.0 - 1.0 * parts[1].length() / length) / taskNum) * 10000);
	    	
	       token = parts[0];
	       
	       if (token.length() > 1 && token.startsWith("PREPROCESSOR")) {
	    	   textTemp.append("<span class = \"preprocessor\">");
	    	   parts = text.split("\r\n", 2);
	    	   text = parts[1];
	    	   textTemp.append(parts[0].replaceAll("PREPROCESSOR", "#"));
	    	   textTemp.append("</span>\r\n");
	    	   continue;
	       }
	       //行注释
	       else if (token.length() > 1 && token.startsWith("LINECOMMENT")) {
	    	   textTemp.append("<span class = \"comment\">");
	    	   parts = text.split("\r\n", 2);
	    	   text = parts[1];
	    	   textTemp.append(parts[0].replaceAll("LINECOMMENT", "//"));
	    	   textTemp.append("</span>\r\n");
	    	   continue;
	       }
	       //块注释
	       else if (token.length() > 1 && token.startsWith("BLOCKCOMMENT")) {
	    	   //textTemp.append("<span class = \"comment\">");
	    	   parts = text.split("\\*/", 2);
	    	   text = parts[1];
	        
	    	   String temp1[] = parts[0].split("\r\n");
	    	   for (int i = 0; i < temp1.length; i++) {
	    		   textTemp.append("<span class = \"comment\">" + 
	    				   temp1[i].replaceAll("BLOCKCOMMENT", "/*") + "</span>\r\n");
		        }
		        textTemp.append("<span class = \"comment\">" + 
			      temp1[temp1.length - 1].replaceAll("BLOCKCOMMENT", "/*") + "*/" + "</span>\r\n");
	    	   continue;
	       }
	       //直接量
	       //token正好为"xxx"的情况
	       	else if (token.startsWith("\"") && token.endsWith("\"") &&
	    	(token.length() > 1)) {
	    	 textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token正好为'xxx'的情况
	      else if (token.startsWith("'") && token.endsWith("'") &&
	               (token.length() > 1)) {
	    	textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token为一个"号的情况,而stringToken判断"号是前面的还是后面的"号
	      else if (token.equals("\"")) {
	        if (stringToken) {
	          textTemp.append(token + "</span>");
	          stringToken = false;
	        }
	        else {
	          textTemp.append("<span class = \"literal\">" + token);
	          stringToken = true;
	        }
	      }
	      else if (token.startsWith("\"")) {
	    	textTemp.append("<span class = \"literal\">" + token);
	        stringToken = true;
	      }
	      else if (token.endsWith("\"") && (!token.endsWith("\\\""))) {
	    	  textTemp.append(token);
	    	  textTemp.append("</span>");
	    	  stringToken = false;
	      }
	      else if (token.matches("\\d+")) { // Check if numeric
	    	  textTemp.append("<span class = \"literal\">" + token +
	                      "</span>");
	      }
	      else if (!stringToken && CppKeywordSet.contains(token)) {
	    	  textTemp.append("<span class = \"keyword\">" + token +
	                      "</span>");
	      }
	      else {
	    	  textTemp.append(token);
	      }

	      if (token.length() < text.length()) {
	        if (text.charAt(token.length()) == '<')
	        	textTemp.append("&lt;");
	        else if (text.charAt(token.length()) == '>')
	        	textTemp.append("&gt;");
	        else
	        	textTemp.append(text.charAt(token.length()));
	      }

	      if (parts.length == 2) {
	        text = parts[1];
	      }
	      
	    }
	    
	    
	    String line[] = textTemp.toString().split("\r\n");
	    for (int i = 0; i < line.length; i++) {
	    	output.format("%s", "<li>" + "<span>" + line[i] + "</span>" + "</li>");
	    }
	    
  
	    output.format("%s\r\n", "</ol>");
	    output.format("%s\r\n", "</pre>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<a id=\"backToTop\" href=\"#top\">");
	    output.format("%s", "<img src=\"" + new File("top.png").getAbsolutePath() + "\"");
	    output.format("%s", "onerror=\"nofind();\"");
	    output.format("%s", " width=\"48\" alt=\"Back to top\" title=\"Back to top\">");
	    output.format("%s\r\n", "</a>");
	    output.format("%s\r\n", "<script type=\"text/javascript\">");
	    output.format("%s\r\n", "function nofind(){");
	    output.format("%s\r\n", "var img=event.srcElement;");
	    output.format("%s\r\n", "img.src=\"http://www.easyicon.net/api/resize_png_new.php?id=1180466&size=48\"; ");
	    output.format("%s\r\n", "img.onerror=null;}");
	    output.format("%s\r\n", "</script>");
	    output.format("%s\r\n", "</body>");
	    output.format("%s\r\n", "</html>");
	    
	    input.close();
        output.close();
		
	}
	
	public static void js2Html() throws FileNotFoundException {
		Scanner input = new Scanner(sourceFile);
		
		File targetFile = new File(folder.getAbsolutePath() + "\\" + 
				sourceFile.getName() + ".html");
		PrintWriter output = new PrintWriter(targetFile);
		
		
		
		output.format("%s\r\n", "<!DOCTYPE HTML>");
		output.format("%s\r\n", "<html>");
	    output.format("%s\r\n", "<head>");
	    output.format("%s\r\n", "<title>" + sourceFile.getName() + "</title>");
	    output.format("%s\r\n", "<style type = \"text/css\">");
	   
	    output.format("%s\r\n", ".orderList {");
	    output.format("%s\r\n", "tab-size:4;");
	    output.format("%s\r\n", "font-family: " + fontType + ", \"Courier New\", Courier, mono, serif;");
	    if (fontSize.equals("small")) {
	    	output.format("%s\r\n", "font-size: 12px;");
	    }
	    else
	    	output.format("%s\r\n", "font-size: " + fontSize + ";"); 
	    output.format("%s\r\n", "background-color: #E7E5DC;");
	    output.format("%s\r\n", "width: 96%;");
	    output.format("%s\r\n", "overflow: auto;");
	    output.format("%s\r\n", "margin: 18px 0 18px 0 !important;");
	    output.format("%s\r\n", "padding-left: 45px;");
	    output.format("%s\r\n", "padding-top: 1px;}");
	    output.format("%s\r\n", "li { list-style: decimal-leading-zero;");
	    output.format("%s\r\n", "list-style-position: outside !important;");
	    output.format("%s\r\n", "border-left: 3px solid #6CE26C;");
	    output.format("%s\r\n", "background-color: #F8F8F8;");
	    output.format("%s\r\n", "color: #5C5C5C;");
	    output.format("%s\r\n", "padding: 0 3px 0 10px !important;");
	    output.format("%s\r\n", "margin: 0 !important;");
	    output.format("%s\r\n", "line-height: 14px; }");
	    output.format("%s\r\n", "span {");
	    output.format("%s\r\n", "color: " + colors[3] + ";}");
	    output.format("%s\r\n", ".keyword {color: " + colors[0] + "; font-weight: bold;}");
	    output.format("%s\r\n", ".comment {color: " + colors[1] + ";}");
	    output.format("%s\r\n", ".literal {color: " + colors[2] + ";}");
	    output.format("%s\r\n", "#backToTop {");
	    output.format("%s\r\n", "position: fixed; bottom: 50px; right: 70px;}");
	    
	    output.format("%s\r\n", "</style>");
	    output.format("%s\r\n", "</head>");
	    output.format("%s\r\n", "<body>");
	    output.format("%s\r\n", "<div class=\"sourceCode\">");
	    output.format("%s\r\n", "<div>");
	    output.format("%s\r\n", "<div class=\"tools\"></div>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<pre>");
	    output.format("%s", "<ol class=\"orderList\">");
	   
	    StringBuilder textTemp = new StringBuilder("");
	    String text = "";
	    String temp;
	    
	    // Read all lines
	    while (input.hasNext()) {
	      temp = input.nextLine();
	      text += temp + "\r\n";
	    }

	    text = text.replaceAll(">", "&gt;");
	    text = text.replaceAll("<", "&lt;");
	    
	    text = text.replaceAll("//", "LINECOMMENT");
	    text = text.replaceAll("/\\*", "BLOCKCOMMENT");
	   
	    
	    long length = text.length();

	    
	    String token;
	   
	    while (text != null && text.length() > 0) {
	    	
	      //利用正则表达式将文本分出一个单词
	       String[] parts = text.split("[%\\+\\-\\*/\r\n\t \\[\\].(){},\\?:\\!=~|^;]", 2);
	       
	       value = (int)((1.0 * done / taskNum + (1.0 - 1.0 * parts[1].length() / length) / taskNum) * 10000);

	       
	       token = parts[0];
	      //行注释
	      if (token.length() > 1 && token.startsWith("LINECOMMENT")) {
	    	textTemp.append("<span class = \"comment\">");
	        parts = text.split("\r\n", 2);
	        text = parts[1];
	        textTemp.append(parts[0].replaceAll("LINECOMMENT", "// "));
	        textTemp.append("</span>\r\n");
	        continue;
	      }
	      //块注释
	      else if (token.length() > 1 && token.startsWith("BLOCKCOMMENT")) {
	    	//textTemp.append("<span class = \"comment\">");
	        parts = text.split("\\*/", 2);
	        text = parts[1];
	        
	        String temp1[] = parts[0].split("\r\n");
	        for (int i = 0; i < temp1.length; i++) {
	        	textTemp.append("<span class = \"comment\">" + 
	        			temp1[i].replaceAll("BLOCKCOMMENT", "/*") + "</span>\r\n");
	        }
	        textTemp.append("<span class = \"comment\">" + 
		      temp1[temp1.length - 1].replaceAll("BLOCKCOMMENT", "/*") + "*/" + "</span>\r\n");
	        continue;
	      }
	      //直接量
	      //token正好为"xxx"的情况
	      else if (token.startsWith("\"") && token.endsWith("\"") &&
	               (token.length() > 1)) {
	    	 textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token正好为'xxx'的情况
	      else if (token.startsWith("'") && token.endsWith("'") &&
	               (token.length() > 1)) {
	    	textTemp.append("<span class = \"literal\">" + token
	                      + "</span>");
	      }
	      //token为一个"号的情况,而stringToken判断"号是前面的还是后面的"号
	      else if (token.equals("\"")) {
	        if (stringToken) {
	          textTemp.append(token + "</span>");
	          stringToken = false;
	        }
	        else {
	          textTemp.append("<span class = \"literal\">" + token);
	          stringToken = true;
	        }
	      }
	      else if (token.startsWith("\"")) {
	    	textTemp.append("<span class = \"literal\">" + token);
	        stringToken = true;
	      }
	      else if (token.endsWith("\"") && (!token.endsWith("\\\""))) {
	    	  textTemp.append(token);
	    	  textTemp.append("</span>");
	    	  stringToken = false;
	      }
	      else if (token.matches("\\d+")) { // Check if numeric
	    	  textTemp.append("<span class = \"literal\">" + token +
	                      "</span>");
	      }
	      else if (!stringToken && JsKeywordSet.contains(token)) {
	    	  textTemp.append("<span class = \"keyword\">" + token +
	                      "</span>");
	      }
	      else {
	    	  textTemp.append(token);
	      }

	      if (token.length() < text.length()) {
	        if (text.charAt(token.length()) == '<')
	        	textTemp.append("&lt;");
	        else if (text.charAt(token.length()) == '>')
	        	textTemp.append("&gt;");
	        else
	        	textTemp.append(text.charAt(token.length()));
	      }

	      if (parts.length == 2) {
	        text = parts[1];
	      }
	      
	    }
	    
	    
	    String line[] = textTemp.toString().split("\r\n");
	    for (int i = 0; i < line.length; i++) {
	    	output.format("%s", "<li>" + "<span>" + line[i] + "</span>" + "</li>");
	    }
	    
  
	    output.format("%s\r\n", "</ol>");
	    output.format("%s\r\n", "</pre>");
	    output.format("%s\r\n", "</div>");
	    output.format("%s\r\n", "<a id=\"backToTop\" href=\"#top\">");
	    output.format("%s", "<img src=\"" + new File("top.png").getAbsolutePath() + "\"");
	    output.format("%s", "onerror=\"nofind();\"");
	    output.format("%s", " width=\"48\" alt=\"Back to top\" title=\"Back to top\">");
	    output.format("%s\r\n", "</a>");
	    output.format("%s\r\n", "<script type=\"text/javascript\">");
	    output.format("%s\r\n", "function nofind(){");
	    output.format("%s\r\n", "var img=event.srcElement;");
	    output.format("%s\r\n", "img.src=\"http://www.easyicon.net/api/resize_png_new.php?id=1180466&size=48\"; ");
	    output.format("%s\r\n", "img.onerror=null;}");
	    output.format("%s\r\n", "</script>");
	    output.format("%s\r\n", "</body>");
	    output.format("%s\r\n", "</html>");
	    
	    input.close();
        output.close();
		
	}
	
	
	public static String getHexString(int number) {
		String result = Integer.toHexString(number);
		
		if (result.length() == 1) {
			result = "0" + result;
		}
		
		return result;
	}
	
	
}
