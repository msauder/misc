;;Clojure for the Brave and True
;;Chapter 4 Exercises
(def filename "suspects.csv")

(def vamp-keys [:name :glitter-index])

(defn str->int
  [str]
  (Integer. str))

(def conversions {:name identity
                  :glitter-index str->int})

(def validations {:name string?
                 :glitter-index number?})

(defn validate
  [validators record]
  (map
   (fn [vamp-key] ((get validators vamp-key) (get record vamp-key)))
   vamp-keys))

(defn convert
  [vamp-key value]
  ((get conversions vamp-key) value))

(defn append
  [suspects suspect]
  (if (every? identity (validate validations suspect))
    (conj suspects suspect)
    (println suspect "INVALID FORM: Vampire suspect must be in form {:name \"fullname\" :glitter-index number}")))

(defn parse
  "Convert a CSV into rows of columns"
  [string]
  (map #(clojure.string/split % #",")
       (clojure.string/split string #"\r\n")))

(defn mapify
  "Return a seq of maps like {:name \"Edward Cullen\" :glitter-index 1-}"
  [rows]
  (map (fn [unmapped-row]
         (reduce (fn [row-map [vamp-key value]]
                   (assoc row-map vamp-key (convert vamp-key value)))
                 {}
                 (map vector vamp-keys unmapped-row)))
       rows))

(defn glitter-filter
  [minimum-glitter records]
  (filter #(>= (:glitter-index %) minimum-glitter) records))

(defn glitter-filter-names
  [minimum-glitter records]
  (map :name (filter #(>= (:glitter-index %) minimum-glitter) records)))

(defn to-csv
  [suspects]
  (clojure.string/join "\r\n" (map #(clojure.string/join "," [(:name %) (:glitter-index %)]) suspects)))

(defn -main
  [& args]
  (def glit3 (glitter-filter 3 (mapify (parse (slurp filename)))))
  (println (glitter-filter-names 3 (mapify (parse (slurp filename)))))
  (def glit3mod (append glit3 {:name "Matthew Sauder" :glitter-index 5}))
  (append glit3 {:name "NAME" :glitter-index "5"})
  (append glit3 {:foo "NAME" :bar 1})
  (to-csv glit3mod))
  
