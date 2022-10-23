array = {"Lua", "Tutorial"}

function elementIterator (collection)

   local index = 0
   local count = #collection
	
   -- The closure function is returned
	
   return function ()
      index = index + 1
		
      if index <= count
      then
         -- return the current element of the iterator
         return collection[index]
      end
		
   end
	
end

for element in elementIterator(array)
do
   print(element)
end
