Dylan Gale

So, my program doesn't actually work and I apologize. I ran into trouble debugging thinking that nothing was working because there were atrifacts
 from it being a windows text file and me running linux as my daily system. I finally figure this out, but this was on Monday. Then I realized that 
the project seems to have wanted me to create four different arrays implementing each collision handling method and then searching through
each of those and retrieving the info. so I went about that for the next day and a half, continuously segfaulting, until finally it hit me that
of course storing 155000 dictionary terms in four different arrays will cause me to run out of memory(4g). SO, I just wanted you to know that 
what I've turned in is me in half a day today trying to make this thing work. The only way I could think to do it the way we are asked is by trying
to make it iterate four times and then create the dictionary array with a different collision handling method, take a word as input, then 
hash and search that array for the info. I couldn't make this work either, so I've commented out anything that is not linear probing for one array
because I know that works. 
