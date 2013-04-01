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