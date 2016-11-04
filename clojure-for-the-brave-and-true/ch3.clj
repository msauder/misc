;;Clojure for the Brave and True
;;Chapter 3 Exercises
(defn add100
  [input]
  (+ input 100))

(defn dec-make
  [dec-by]
  #(- % dec-by))

(defn mapset
  [f input]
  (set (map f input)))

(def unrad-body-parts [{:name "head" :size 3}
                       {:name "eye-1" :size 1}
                       {:name "ear-1" :size 1}
                       {:name "mouth" :size 1}
                       {:name "nose" :size 1}
                       {:name "neck" :size 2}
                       {:name "shoulder-1" :size 3}
                       {:name "upper-arm-1" :size 3}
                       {:name "chest" :size 10}
                       {:name "back" :size 10}
                       {:name "forearm-1" :size 3}
                       {:name "abdomen" :size 6}
                       {:name "kidney-1" :size 1}
                       {:name "hand-1" :size 2}
                       {:name "knee-1" :size 2}
                       {:name "thigh-1" :size 4}
                       {:name "lower-leg-1" :size 3}
                       {:name "achilles-1" :size 1}
                       {:name "foot-1" :size 2}])

(defn matching-part
  [part num]
  {:name (clojure.string/replace (:name part) #"-1$" (str "-" num))
   :size (:size part)})

(defn radiate-body-parts
  "Expects a seq of maps that have a :name and :size"
  [unrad-body-parts]
  (loop [remaining-unrad-parts unrad-body-parts
         final-body-parts []]
    (if (empty? remaining-unrad-parts)
      final-body-parts
      (let [[part & remaining] remaining-unrad-parts]
        (recur remaining
               (into final-body-parts
                     (set [part
                           (matching-part part 2)
                           (matching-part part 3)
                           (matching-part part 4)
                           (matching-part part 5)])))))))

(defn multi-radiate-body-parts
  "Expects a seq of maps that have a :name and :size"
  [unrad-body-parts multi]
  (loop [remaining-unrad-parts unrad-body-parts
         final-body-parts []]
    (if (empty? remaining-unrad-parts)
      final-body-parts
      (let [[part & remaining] remaining-unrad-parts]
        (recur remaining
               (into final-body-parts
                     (set (map #(matching-part part %)
                                (range 1 (+ multi 1))))))))))
