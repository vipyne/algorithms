class HashTable

  def initialize
    @size = 1000;
    @dictionary = Array.new(@size)
  end

  def iterate_through_this(word, prime)
    word.each_char do |char|
      prime *= 11 + char.ord
    end
    prime
  end

  # riff on djb2 hash function (5381 was waaaaaaaay overkill for this scale)
  def hash_this(word)
    hash = 11
    iterate_through_this(word, hash)
    hash %= @size
    if hash == 0
      hash = 7
      iterate_through_this(word, hash)
    end
    hash %= @size
  end

  def insert_this(word, hashed_word)
    if @dictionary[hashed_word] == nil
      @dictionary[hashed_word] = word
    elsif @dictionary[hashed_word].kind_of?(Array)
      @dictionary[hashed_word].push(word)
    else
      @dictionary[hashed_word] = Array.new(1, @dictionary[hashed_word]).push(word)
    end
  end

  def add_this(word)
    hashed = hash_this(word)
    insert_this(word, hashed)
  end

  def lookup(word)
    hashed_word = hash_this(word)
    if @dictionary[hashed_word] != nil
      puts "\"#{word}\" is in dictionary"
      return word
    else
      puts "\"#{word}\" is not in dictionary"
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
dict.lookup("cubertical")