# broken WIP

class HashTable

  def initialize
    @size = 1000;
    @dictionary = Array.new(@size)
  end

  # riff on djb2 hash function
  def hash_this(word)
    hash = 5381
    word.each_char do |char|
      hash *= 33 + char.ord
    end
    hash % @size
  end

  def insert_this(word, hashed_word)
    if @dictionary[hashed_word] == nil
      @dictionary[hashed_word] = word
    elsif @dictionary[hashed_word].kind_of?(Array)
      @dictionary[hashed_word].push(word)
    else
      @dictionary[hashed_word] = Array.new(2, @dictionary[hashed_word], word)
    end
  end

  def add_this(word)
    hashed = hash_this(word)
    insert_this(word, hashed)
  end

  def lookup(word)
    hashed_word = hash_this(word)
    if @dictionary[hashed_word] != nil
      puts word
      return word
    else
      puts "#{word} is not in dictionary"
      return nil
    end
  end

  def delete_this(word)
    @dictionary[hash_this(word)] = nil
  end

end

dict = HashTable.new

dict.add_this("juxtaposition")
dict.add_this("elucidate")
dict.lookup("juxtaposition")
dict.lookup("cubical")