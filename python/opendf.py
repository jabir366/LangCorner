import PyPDF2
import sys
from datetime import datetime, timedelta

def get_date_range(start_date, end_date):
    """
    Returns a list of dates in the format ddmmyyyy between two dates (inclusive).

    Parameters:
    start_date (str): The starting date in the format ddmmyyyy.
    end_date (str): The ending date in the format ddmmyyyy.

    Returns:
    list: A list of dates in the format ddmmyyyy.
    """
    # Convert the input strings to datetime objects
    start_dt = datetime.strptime(start_date, '%d%m%Y')
    end_dt = datetime.strptime(end_date, '%d%m%Y')

    # Create an empty list to hold the dates
    date_list = []

    # Loop through each date in the range and add it to the list
    while start_dt <= end_dt:
        date_str = start_dt.strftime('%d%m%Y')
        date_list.append(date_str)
        start_dt += timedelta(days=1)

    return date_list

def brute_force_pdf(pdf_file_path, password_list):
    """
    Attempt to open a PDF file with a list of passwords.

    Parameters:
    pdf_file_path (str): The path to the PDF file.
    password_list (list): A list of passwords to try.

    Returns:
    str: The password that successfully unlocks the PDF, or None if no password is found.
    """
    # Open the PDF file in read-binary mode
        # Create a PdfFileReader object
    pdf_reader = PyPDF2.PdfReader(pdf_file_path)

    # Iterate over the password list and try each password
    for password in password_list:
        if pdf_reader.decrypt(password) == 1:
            # If the password is correct, return it
            return password

    # If no password is found, return None
    return None


def main():

    date_range = get_date_range('01011959','01011961')
    filename = sys.argv[1]
    ret = brute_force_pdf(filename,date_range)
    if(  ret):
        print("Password success:",ret)
    else:
        print("Passwords does not match")

if __name__ == '__main__':
    main()
