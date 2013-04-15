class Entity
    attr_reader :table, :ident

    def initialize(table, ident)
        @table = table
        @ident = ident
        # Database.sql "INSERT INTO #{@table} (id) VALUES (#{@ident})"
        puts "INSERT INTO #{@table} (id) VALUES (#{@ident})"
    end

    def set (col, val)
        # Database.sql "UPDATE #{@table} SET #{col}='#{val}' WHERE id=#{@ident}"
        puts "UPDATE #{@table} SET #{col}='#{val}' WHERE id=#{@ident}"
    end

    def get(col)
        # Database.sql("SELECT #{col} FROM #{@table} WHERE id=#{@ident}")[0][0]
        puts "SELECT #{col} FROM #{@table} WHERE id=#{@ident}"
    end
end

class Movie < Entity
    def initialize(ident)
        super("movies", ident)
    end

    def title
        get("title")
    end

    def title=(value)
        set("ttile", value)
    end

    def director
        get("director")
    end

    def director=(value)
        set("director", value)
    end
end

movie = Movie.new(1)
movie.title = "Doctor Strangelove"
movie.director = "Stanley Kubrick"
