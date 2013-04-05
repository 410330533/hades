(+ 1 1)
(* 10 10)
(/ 1 3)
(mod 5 4)
(/ (/ 12 2) (/ 6 2))
(+ 2 2 2 2)
(- 8 1 2)
(< 1 3 2 4)

(println "master yoda\nluke skywalker\ndarth vader")
(str "yoda, " "luke, " "darth")
(str \f \o \r \c \e)
(if true (println "True it is."))

; list
(list 1 2 3)
'(1 2 3)
(first '(:r2d2 :c3po))
(last '(:r2d2 :c3po))
(rest '(:r2d2 :c3po))
(cons :battle-droid '(:r2d2 :c3po))

; vector
[:hutt :wookie :ewok]
(first [:hutt :wookie :ewok])
(rest [:hutt :wookie :ewok])
(nth [:hutt :wookie :ewok] 2)
(nth [:hutt :wookie :ewok] 0)
(last [:hutt :wookie :ewok])
([:hutt :wookie :ewok] 2)
(concat [:darth-vader] [:darth-maul])

; set
#{:x-wing :y-wing :tie-fighter}
(def spacecraft #{:x-wing :y-wing :tie-fighter})
(count spacecraft)
(sort spacecraft)
(sorted-set 2 3 1)
(clojure.set/union #{:skywalker} #{:vader})
(clojure.set/difference #{1 2 3} #{2})
(#{:jar-jar :chewbacca} :chewbacca)
(#{:jar-jar :chewbacca} :luke)

; map
{:chewie :wookie, :lea :human}
{:darth-vader "obi wan", :luke "yoda"}
(def mentors {:darth-vader "obi wan", :luke "yoda"})
(mentors :luke)
(:luke mentors)
(merge {:y-wing 2, :x-wing 4} {:tie-fighter 2})
(merge-with + {:y-wing 2, :x-wing 4} {:tie-fighter 2 :x-wing 3})
(assoc {:one 1} :two 2)
(sorted-map 1 :one, 3 :three, 2 :two)

; function
(defn force-it
    "The first function a young Jedi needs"
    [jedi]
    (str "Use the force, " jedi))
(force-it "Luke")
(doc force-it)
(doc str)

; bind
(def line [[0 0] [10 20]])
(defn line-end [ln] (last ln))
(line-end line)
(defn line-end [[_ second]] second)
(line-end line)

(def board [[:x :o :x] [:o :x :o] [:o :x :o]])
(defn center [[_ [_ c _] _]] c)
(center board)
(defn center [board]
    (let [[_ [_ c]] board] c))

(def person {:name "Jabba" :profession "Gangster"})
(let [{name :name} person] (str "The person's name is " name))

(def villains [{:name "Godzilla" :size "big"} {:name "Ebola" :size "small"}])
(let [[_ {name :name}] villains] (str "Name of the second villain: " name))

; anonymous function
(def people ["Lea", "Han Solo"])
(map count people)

(defn twice-count[w] (* 2 (count w)))
(map twice-count people)
(map (fn [w] (* 2 (count w))) people)
(map #(* 2 (count %)) people)

(def v [3 1 2])
(apply + v)
(apply max v)

(filter odd? v)
(filter #(< % 3) v)

; loop & recur
(defn size [v]
    (if (empty? v)
        0
        (inc (size (rest v)))))
(size [1 2 3])
; (loop [x x-initial-value, y y-initial-value] (do-something-with x y))

; list
(every? number? [1 2 3 :four])
(some nil? [1 2 nil])
(not-every? odd? [1 3 5])
(not-any? number? [:one :two :three])

(def words ["luke" "chewie" "han" "lando"])
(filter (fn [word] (> (count word) 4)) words)

(map (fn [x] (* x x)) [1 1 2 3 5])

(def colors ["red" "blue"])
(def toys ["block" "car"])
(for [x colors] (str "I like " x))
(for [x colors, y toys] (str "I like " x " " y "s"))

(defn small-word? [w] (< (count w) 4))
(for [x colors, y toys, :when(small-word? y)]
    (str "I like " x " " y "s"))

(reduce + [1 2 3 4])
(reduce * [1 2 3 4 5])
(sort [3 1 2 4])
(defn abs [x] (if (< x 0) (- x) x))
(sort-by abs [-1 -4 3 2])

; delay calculate
(range 1 10)
(range 1 10 3)
(range 10)

(take 3 (repeat "Use the Force, Luke"))
(take 5 (cycle [:lather :rinse :repeat]))
(take 5 (drop 2 (cycle [:lather :rinse :repeat])))
(->> [:lather :rinse :repeat] (cycle) (drop 2) (take 5))
(take 5 (interpose :and (cycle [:lather :rinse :repeat])))
(take 20 (interleave (cycle (range 2)) (cycle (range 3))))
(take 5 (iterate inc 1))
(take 5 (iterate dec 0))

(defn fib-pair [[a b]] [b (+ a b)])
(fib-pair [3 5])
(take 5 (map first (iterate fib-pair [1 1])))
(nth (map first (iterate fib-pair [1 1])) 50)
(defn factorial [n] (apply * (take n (iterate inc 1))))
(factorial 5)

; ref
(def movie (ref "Star Wars"))
(deref movie)
@movie
(dosync (alter movie str ": The Empire Strikes Back"))
(dosync (ref-set movie "Star Wars: The Revenge of the Sith"))

; atom
(atom "Split at your own risk.")
(def danger (atom "Split at your own risk."))
@danger
(reset! danger "Split with impunity")

(def top-sellers (atom []))
(swap! top-sellers conj {:title "Seven Languages in Seven Weeks", :author "Tate"})
(swap! top-sellers conj {:title "Programming Clojure", :author "Tate"})

; 构建原子缓存
(defn create [] (atom {}))
(defn get [cache key] (@cache key))
(defn put
    ([cache value-map]
        (swap! cache merge value-map))
    ([cache key value]
        (swap! cache assoc key value)))
(def ac (create))
(put ac :quote "I'm your father, Luke.")
(println (str "Cached item: " (get ac :quote)))

; agent
(defn twice [x] (* 2 x))
(def tribbles (agent 1))
(send tribbles twice)
@tribbles

(defn slow-twice [x]
    (do
        (Thread/sleep 5000)
        (* 2 x)))
@tribbles
(send tribbles slow-twice)
@tribbles
; 5s later
@tribbles

; future
(def finer-things (future (Thread/sleep 5000) "take time"))
@finer-things