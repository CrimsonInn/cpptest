#include <iostream>
#include <fstream>
#include <string>
#include "test_protobuf.h"

using namespace std;

void write_protobuf(){

  cout << "Test write protobuf ... " << endl;
  
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  // Test for protobuf
  // fill in a person message into address book
  // person information parameters
  int id = 1;
  string name = "cs205";
  string email = "cs205@harvard.edu";
  string tel_number = "123-456-7890";
  string tel_type = "mobile";
  string file_name = "DEMO_ADDRESS_BOOK_FILE"; //protobuf file name

  // init an address book variable
  tutorial::AddressBook write_address_book;

  // Read the existing address book.
  fstream input(file_name, ios::in | ios::binary);
  if (!input) {
    cout << file_name << ": File not found. Creating a new file." << endl;
  } else if (!write_address_book.ParseFromIstream(&input)) {
    cerr << "Failed to parse address book." << endl;
    return ;
  }

  // write into address_book
  tutorial::Person* person = write_address_book.add_people();
  (*person).set_id(id);
  (*person).set_name(name);
  (*person).set_email(email);
  tutorial::Person::PhoneNumber* phone_number = (*person).add_phones();
  (* phone_number).set_number(tel_number);
  if (tel_type == "mobile") {
    (* phone_number).set_type(tutorial::Person::MOBILE);
  } else if (tel_type == "home") {
    (* phone_number).set_type(tutorial::Person::HOME);
  } else if (tel_type == "work") {
    (* phone_number).set_type(tutorial::Person::WORK);
  } else {
    cout << "Unknown phone type.  Using default." << endl;
  }

  // Write the new address book back to disk.
  fstream output(file_name, ios::out | ios::trunc | ios::binary);
  if (!write_address_book.SerializeToOstream(&output)) {
    cerr << "Failed to write address book." << endl;
    return ;
  } else {
    cout << "Success: add a new person." << endl;
    cout << "Done!" <<endl;
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

}

