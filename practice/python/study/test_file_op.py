print ("File Operator Testing")

# read text file
print("read text file")
f = open("demo_file.txt", "rt")
print(f.read())
f.close()

# read part of file
print("read part of file")
f = open("demo_file.txt", "rt")
print(f.read(10))
f.close()


# read each line
print("read each line")
f = open("demo_file.txt", "rt")
print(f.readline())
f.close()


# loop read
print("loop read")
f = open("demo_file.txt", "rt")
for i in f:
    print(i)
f.close()


## write file.
print("write file")
f = open("demo_file.txt", "w")
f.write("New content\n")
f.close()

f = open("demo_file.txt", "rt")
print(f.read())
f.close()

## append more content
print("append more content")
f = open("demo_file.txt", "a")
f.write("Add more content")
f.close()

f = open("demo_file.txt", "rt")
print(f.read())
f.close()


