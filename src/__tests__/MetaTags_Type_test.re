open Jest;

open ExpectJs;

module Make (MetaTags: MetaTags.Interface) => {
  let setup ::the_type => {
    module Type = MetaTags_Type.Make MetaTags;
    Enzyme.shallow <Type the_type />
  };
};

describe
  "Type"
  (
    fun () =>
      test
        "render and get type"
        (
          fun () => {
            module MetaTags = MetaTags.Make ();
            module Context = Make MetaTags;
            let the_type = "article";
            let _ = Context.setup ::the_type;
            expect (MetaTags.the_type ()) |> toEqual the_type
          }
        )
  );