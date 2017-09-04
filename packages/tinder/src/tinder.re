module TinderClient = {
  type t =
    Js.t {
      .
      authorize : (string => string => callback 'any => unit) [@bs.meth],
      isAuthorized : (unit => boolean) [@bs.meth],
      getAuthToken : (unit => string) [@bs.meth],
      setAuthToken : (string => unit) [@bs.meth],
      getDefaults : (unit => 'any) [@bs.meth],
      userId : string,
      getRecommendations : (float => callback tinderRecommendationsResult => unit) [@bs.meth],
      sendMessage : (string => string => callback 'any => unit) [@bs.meth],
      like : (string => callback 'any => unit) [@bs.meth],
      superLike : (string => callback 'any => unit) [@bs.meth],
      pass : (string => callback 'any => unit) [@bs.meth],
      unmatch : (string => callback 'any => unit) [@bs.meth],
      getUpdates : (callback tinderUpdates => unit) [@bs.meth],
      getHistory : (callback tinderHistory => unit) [@bs.meth],
      updatePosition : (number => number => callback 'any => unit) [@bs.meth],
      getAccount : (callback 'any => unit) [@bs.meth],
      updatePreferences :
        (boolean => float => float => float => float => callback 'any => unit) [@bs.meth],
      uploadPicture : (readStream => callback 'any => unit) [@bs.meth],
      uploadFBPicture :
        (string => float => float => float => float => callback 'any => unit) [@bs.meth],
      deletePicture : (string => callback 'any => unit) [@bs.meth],
      getProfile : (callback 'any => unit) [@bs.meth],
      updateGender : (float => callback 'any => unit) [@bs.meth],
      updateBio : (string => callback 'any => unit) [@bs.meth],
      updateJob : (string => callback 'any => unit) [@bs.meth],
      deleteJob : (callback 'any => unit) [@bs.meth],
      updateSchool : (string => callback 'any => unit) [@bs.meth],
      deleteSchool : (callback 'any => unit) [@bs.meth],
      deleteAccount : (callback 'any => unit) [@bs.meth],
      getUser : (string => callback 'any => unit) [@bs.meth],
      getShareLink : (string => callback 'any => unit) [@bs.meth],
      report : (string => number => string => callback 'any => unit) [@bs.meth],
      createUsername : (string => callback 'any => unit) [@bs.meth],
      changeUsername : (string => callback 'any => unit) [@bs.meth],
      deleteUsername : (string => callback 'any => unit) [@bs.meth],
      updatePassport : (string => string => callback 'any => unit) [@bs.meth],
      resetPassport : (callback 'any => unit) [@bs.meth]
    };
  external make : unit => t = "TinderClient" [@@bs.new] [@@bs.module "tinder"];
};

type callback 't = Js.t {..};

type tinderUpdates =
  Js.t {
    ..
    matches : array 'any,
    blocks : array 'any,
    matchmaker : array 'any,
    lists : array 'any,
    deleted_lists : array 'any,
    liked_messages : array tinderMessage,
    squads : array 'any,
    last_activity_date : string
  };

type tinderRecommendationsResult =
  Js.t {.. message : string, status : number, results : array tinderRecommendation};

type tinderRecommendation =
  Js.t {
    ..
    distance_mi : number,
    common_connections : array 'any,
    common_likes : array 'any,
    common_interests : array 'any,
    uncommon_interests : array 'any,
    common_friends : array 'any,
    _id : string,
    badges : array 'any,
    bio : string,
    birth_date : string,
    gender : float,
    name : string,
    ping_time : string,
    photos : array tinderPhoto,
    jobs : array 'any,
    schools : array 'any,
    teaser : Js.t {.. string : string},
    birth_date_info : string
  };

type tinderHistory =
  Js.t {
    ..
    matches : array tinderMatch,
    blocks : array string,
    lists : array 'any,
    deleted_lists : array 'any,
    liked_messages : array tinderLikedMessage,
    squads : array 'any,
    last_activity_date : string
  };

type tinderLikedMessage =
  Js.t {
    ..
    message_id : string,
    updated_at : string,
    liker_id : string,
    match_id : string,
    is_liked : boolean
  };

type tinderMatch =
  Js.t {
    ..
    _id : string,
    closed : boolean,
    common_friend_count : float,
    common_like_count : float,
    created_date : string,
    dead : boolean,
    last_activity_date : string,
    message_count : float,
    messages : array tinderMessage,
    muted : boolean,
    participants : array string,
    pending : boolean,
    is_super_like : boolean,
    following : boolean,
    following_moments : boolean,
    id : string,
    person : tinderPerson
  };

type tinderPerson =
  Js.t {
    ..
    _id : string,
    bio : string,
    birth_date : string,
    gender : float,
    name : string,
    ping_time : string,
    user_number : float,
    photos : array tinderPhoto,
    badges : array 'any
  };

type tinderPhoto =
  Js.t {
    ..
    url : string,
    processedFiles : array tinderPhotoProcessedFile,
    extension : string,
    fileName : string,
    xoffset_percent : float,
    ydistance_percent : float,
    main : boolean,
    xdistance_percent : float,
    id : string,
    yoffset_percent : float
  };

type tinderPhotoProcessedFile = Js.t {.. url : string, height : float, width : float};

type tinderMessage =
  Js.t {
    ..
    _id : string,
    match_id : string,
    _to : string,
    from : string,
    message : string,
    sent_date : string,
    created_date : string,
    timestamp : float
  };
