**For C++:**  
protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/demo.proto

**For Python:**  
protoc -I=. --python_out=. demo.proto