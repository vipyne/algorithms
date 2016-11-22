# WIP // not working just yet

# a Tarot deck has 78 cards of which 4 are aces
# the deck is in one pile face down. we pick off and
# turn over the top 13 cards. unless we turn over an ace -
# then we start the count to 13 over again.



CHANCES = 13.0
@memoized_1 = {}
@memoized_2 = {}

@probability = 0.0

def likelyhood_of_ace(aces, cards, chances_left)
  if (chances_left <= 0 || cards <= 0 && aces > 0)
    puts 'nerd'
    @memoized_1.each do |k, v|
      p 'fsadf'
      p v
      @probability += v
    end
    # @memoized_1 = {}
    return 0
  else
    @memoized_1["#{cards-1}" + "#{chances_left-1}"] ||= likelyhood_of_ace( aces, cards-1, chances_left-1 )
  end

  if (aces <= 0 || cards <=0 && chances_left > 0)
    # puts '---derp'
    @memoized_2.each do |k, v|
      p 'v'
      p v
      @probability += v
    end
    # @memoized_2 = {}
    return 0
  else
    @memoized_2["#{aces-1}" + "#{cards-1}"] ||= likelyhood_of_ace( aces-1, cards-1, CHANCES )
  end

  # puts "aces / cards".chomp
  # puts aces/cards
  # puts 'probability'.chomp
  puts @probability
  puts @probability

  # @memoized_1 = {}
  # @memoized_2 = {}
  # @probability = 0.0

  return aces/cards
end


likelyhood_of_ace(4.0, 78.0, 13.0)