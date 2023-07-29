//#[warn(unused_mut)]
fn main(){
    let mut course = String::from("SSS");
    let mut course2 = String::from("");
    let mut s2 = "new";
    let mut s3 = "nwewewesdsdsdsdsdsdsdsdsadsfafsdaw";
    course.push_str(s2);
    course2.push_str(s3);
    // course.push('d');
    // course.push("d");
    println!("THis is empty {}",course.len());
    println!("capacity of variable is {} {}",course,course.capacity());
    println!("capacity of variable is {}",course2.len());
    for item in course.bytes(){
          println!("{}",item);  
    }

}
fn test(my_str:String)-> String {
    // Write code here
    let mut filtered_str = "".to_string();
    for word in my_str.split_whitespace(){
        if word.starts_with("c"){
            // filtered_str.push_str(&(word.to_owned()+&String::from(" ")));
            // filtered_str.push_str(&(word.to_owned()+&" ".to_string()));
            

        }
    }
   filtered_str.to_string()
}



//To learn
//Copy type and moved type
// struct Sample{}
impl Sample{
    fn sam(){
    println!("Hi");
    }
}

fn reverse1(input: &str) -> String{
    let initial = "cat".to_string();
    // Get chars from string (Chars iterator returned).
    // Reverse the chars (Rev iterator returned).
    // Call Collect to convert Char iterator into String.
    let reversed: String = initial.chars().rev().collect();
    println!("{reversed}");
}

fn reverse_alternate(initial: &str) -> String {
    // Get chars from string.
    let chars: Vec<char> = initial.chars().collect();
    // Allocate new string.
    let mut reversed = String::new();
    // Add chars in reverse order, stopping at 0.
    let mut index = initial.len() - 1;
    loop {
        reversed.push(chars[index]);
        if index == 0 {
            break;
        }
        index -= 1;
    }
    reversed
}
