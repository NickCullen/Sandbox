
print( "[lua] These args were passed into the script from C\n" );

print(arg)
for i=1,#arg do
   print(i,arg[i])
end
