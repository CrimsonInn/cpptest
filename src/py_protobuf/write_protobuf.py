#! /usr/bin/env python

#import addressbook_pb2
import sys
sys.path.append("./")
from protobuf import demo_pb2

# This function fills in a Person message based on user input.
def PromptForAddress(person):
  person.id = 2
  person.name = "cd205_python"
  person.email = "cd205_python@harvard.edu"

  phone_number = person.phones.add()
  phone_number.number = "123-456-7890"
  phone_number.type = demo_pb2.Person.HOME

# Main procedure:  Reads the entire address book from a file,
#   adds one person based on user input, then writes it back out to the same
#   file.
if len(sys.argv) != 2:
  print ("Usage:", sys.argv[0], "ADDRESS_BOOK_FILE")
  sys.exit(-1)

address_book = demo_pb2.AddressBook()

# Read the existing address book.
try:
  with open(sys.argv[1], "rb") as f:
    address_book.ParseFromString(f.read())
except IOError:
  print (sys.argv[1] + ": File not found.  Creating a new file.")

# Add an address.
PromptForAddress(address_book.people.add())

# Write the new address book back to disk.
with open(sys.argv[1], "wb") as f:
  f.write(address_book.SerializeToString())
